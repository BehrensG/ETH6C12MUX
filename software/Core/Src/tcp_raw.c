
#include "lwip/debug.h"
#include "lwip/stats.h"
#include "lwip/tcp.h"

#include "scpi/scpi.h"
#include "scpi_def.h"
#include "tcp_raw.h"

struct tcp_pcb *tcp_raw_pcb;
struct echo_state* es_scpi;

/* ECHO protocol states */
enum tcp_raw_states
{
  ES_NONE = 0,
  ES_ACCEPTED,
  ES_RECEIVED,
  ES_CLOSING
};

static err_t tcp_raw_accept(void *arg, struct tcp_pcb *newpcb, err_t err);
static err_t tcp_raw_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);
static void tcp_raw_error(void *arg, err_t err);
static err_t tcp_raw_poll(void *arg, struct tcp_pcb *tpcb);
 err_t tcp_raw_sent(void *arg, struct tcp_pcb *tpcb, u16_t len);
static void tcp_raw_connection_close(struct tcp_pcb *tpcb, struct tcp_raw_struct *es);

struct tcp_pcb *gtpcb;
/**
  * @brief  Initializes the tcp echo server
  * @param  None
  * @retval None
  */
void tcp_raw_init(void)
{
  /* create new tcp pcb */
  tcp_raw_pcb = tcp_new();

  if (tcp_raw_pcb != NULL)
  {
    err_t err;


      err = tcp_bind(tcp_raw_pcb, IP_ADDR_ANY, 5025);

    if (err == ERR_OK)
    {
      /* start tcp listening for echo_pcb */
      tcp_raw_pcb = tcp_listen(tcp_raw_pcb);

      /* initialize LwIP tcp_accept callback function */
      tcp_accept(tcp_raw_pcb, tcp_raw_accept);
    }
    else
    {
     // printf("Can not bind pcb\n");
    }
  }
  else
  {
   // printf("Can not create new pcb\n");
  }
}

/**
  * @brief  This function is the implementation of tcp_accept LwIP callback
  * @param  arg: not used
  * @param  newpcb: pointer on tcp_pcb struct for the newly created tcp connection
  * @param  err: not used
  * @retval err_t: error status
  */
static err_t tcp_raw_accept(void *arg, struct tcp_pcb *newpcb, err_t err)
{
  err_t ret_err;
  struct tcp_raw_struct *es;

  LWIP_UNUSED_ARG(arg);
  LWIP_UNUSED_ARG(err);

  /* set priority for the newly accepted tcp connection newpcb */
  tcp_setprio(newpcb, TCP_PRIO_MIN);

  /* allocate structure es to maintain tcp connection informations */
  es = (struct tcp_raw_struct *)mem_malloc(sizeof(struct tcp_raw_struct));
  if (es != NULL)
  {
    es->state = ES_ACCEPTED;
    es->pcb = newpcb;
    es->p = NULL;

    /* pass newly allocated es structure as argument to newpcb */
    tcp_arg(newpcb, es);

    /* initialize lwip tcp_recv callback function for newpcb  */
    tcp_recv(newpcb, tcp_raw_recv);

    /* initialize lwip tcp_err callback function for newpcb  */
    tcp_err(newpcb, tcp_raw_error);

    /* initialize lwip tcp_poll callback function for newpcb */
    tcp_poll(newpcb, tcp_raw_poll, 1);

    ret_err = ERR_OK;
  }
  else
  {
    /* return memory error */
    ret_err = ERR_MEM;
  }
  return ret_err;
}


/**
  * @brief  This function is the implementation for tcp_recv LwIP callback
  * @param  arg: pointer on a argument for the tcp_pcb connection
  * @param  tpcb: pointer on the tcp_pcb connection
  * @param  pbuf: pointer on the received pbuf
  * @param  err: error information regarding the reveived pbuf
  * @retval err_t: error code
  */
static err_t tcp_raw_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
  // struct tcp_raw_struct *es;
  err_t ret_err;
  uint8_t tmp_payload[256];
  uint16_t tmp_len = 0;


  LWIP_ASSERT("arg != NULL",arg != NULL);

  es_scpi = (struct tcp_raw_struct *)arg;

  /* if we receive an empty tcp frame from client => close connection */
  if (p == NULL)
  {
    /* remote host closed connection */
    es_scpi->state = ES_CLOSING;
    if(es_scpi->p == NULL)
    {
       /* we're done sending, close connection */
       tcp_raw_connection_close(tpcb, es_scpi);
    }
    else
    {
      /* we're not done yet */
      /* acknowledge received packet */
      //tcp_sent(tpcb, tcp_raw_sent);

      /* send remaining data*/
      //tcp_raw_send(tpcb, es_scpi);
    }
    ret_err = ERR_OK;
  }
  /* else : a non empty frame was received from client but for some reason err != ERR_OK */
  else if(err != ERR_OK)
  {
    /* free received pbuf*/
    if (p != NULL)
    {
      es_scpi->p = NULL;
      pbuf_free(p);
    }
    ret_err = err;
  }
  else if(es_scpi->state == ES_ACCEPTED)
  {
    /* first data chunk in p->payload */
    es_scpi->state = ES_RECEIVED;

    /* store reference to incoming pbuf (chain) */
    es_scpi->p = p;

     /* initialize LwIP tcp_sent callback function */
    tcp_sent(tpcb, tcp_raw_sent);
    memcpy(tmp_payload, es_scpi->p->payload, es_scpi->p->len);
    tmp_len = es_scpi->p->len;
          es_scpi->p->len = 0;
      strcpy(es_scpi->p->payload,"");
    SCPI_Input(&scpi_context, tmp_payload, tmp_len);


    /* send back the received data (echo) */
    tcp_raw_send(tpcb, es_scpi);
    ret_err = ERR_OK;
  }
  else if (es_scpi->state == ES_RECEIVED)
  {
    /* more data received from client and previous data has been already sent*/
    if(es_scpi->p == NULL)
    {
      es_scpi->p = p;

      /* send back received data */
    memcpy(tmp_payload, es_scpi->p->payload, es_scpi->p->len);
      tmp_len = es_scpi->p->len;
      es_scpi->p->len = 0;
      strcpy(es_scpi->p->payload,"");
    SCPI_Input(&scpi_context, tmp_payload, tmp_len);
    tcp_raw_send(tpcb, es_scpi);
    }
    else
    {
      struct pbuf *ptr;

      /* chain pbufs to the end of what we recv'ed previously  */
      ptr = es_scpi->p;
      pbuf_chain(ptr,p);
    }
    ret_err = ERR_OK;
  }
  /* data received when connection already closed */
  else
  {
    /* Acknowledge data reception */
    tcp_recved(tpcb, p->tot_len);

    /* free pbuf and do nothing */
    es_scpi->p = NULL;
    pbuf_free(p);
    ret_err = ERR_OK;
  }
  return ret_err;
}

/**
  * @brief  This function implements the tcp_err callback function (called
  *         when a fatal tcp_connection error occurs.
  * @param  arg: pointer on argument parameter
  * @param  err: not used
  * @retval None
  */
static void tcp_raw_error(void *arg, err_t err)
{
  struct tcp_raw_struct *es;

  LWIP_UNUSED_ARG(err);

  es = (struct tcp_raw_struct *)arg;
  if (es != NULL)
  {
    /*  free es structure */
    mem_free(es);
  }
}

/**
  * @brief  This function implements the tcp_poll LwIP callback function
  * @param  arg: pointer on argument passed to callback
  * @param  tpcb: pointer on the tcp_pcb for the current tcp connection
  * @retval err_t: error code
  */
static err_t tcp_raw_poll(void *arg, struct tcp_pcb *tpcb)
{
  err_t ret_err;
  struct tcp_raw_struct *es;

  es = (struct tcp_raw_struct *)arg;
  if (es != NULL)
  {
    if (es->p != NULL)
    {
      /* there is a remaining pbuf (chain) , try to send data */
      tcp_raw_send(tpcb, es);
    }
    else
    {
      /* no remaining pbuf (chain)  */
      if(es->state == ES_CLOSING)
      {
        /*  close tcp connection */
        tcp_raw_connection_close(tpcb, es);
      }
    }
    ret_err = ERR_OK;
  }
  else
  {
    /* nothing to be done */
    tcp_abort(tpcb);
    ret_err = ERR_ABRT;
  }
  return ret_err;
}

/**
  * @brief  This function implements the tcp_sent LwIP callback (called when ACK
  *         is received from remote host for sent data)
  * @param  None
  * @retval None
  */
err_t tcp_raw_sent(void *arg, struct tcp_pcb *tpcb, u16_t len)
{
  struct tcp_raw_struct *es;
  LWIP_UNUSED_ARG(len);

  es = (struct tcp_raw_struct *)arg;

  if(es->p != NULL)
  {
    /* still got pbufs to send */
    tcp_raw_send(tpcb, es);
  }
  else
  {
    /* if no more data to send and client closed connection*/
    if(es->state == ES_CLOSING)
      tcp_raw_connection_close(tpcb, es);
  }
  return ERR_OK;
}


/**
  * @brief  This function is used to send data for tcp connection
  * @param  tpcb: pointer on the tcp_pcb connection
  * @param  es: pointer on echo_state structure
  * @retval None
  */
void tcp_raw_send(struct tcp_pcb *tpcb, struct tcp_raw_struct *es)
{
  struct pbuf *ptr;
  uint16_t pbuf_size = 0;

  err_t wr_err = ERR_OK;
  pbuf_size = tcp_sndbuf(tpcb);

  while ((wr_err == ERR_OK) &&
         (es->p != NULL) &&
         (es->p->len <= tcp_sndbuf(tpcb)))
  {

    /* get pointer on pbuf from es structure */
    ptr = es->p;
    /* enqueue data for transmission */
    wr_err = tcp_write(tpcb, ptr->payload, ptr->len, 1);

    if (wr_err == ERR_OK)
    {
      u16_t plen;

      plen = ptr->len;

      /* continue with next pbuf in chain (if any) */
      es->p = ptr->next;

      if(es->p != NULL)
      {
        /* increment reference count for es->p */
        pbuf_ref(es->p);
      }

      /* free pbuf: will free pbufs up to es->p (because es->p has a reference count > 0) */
      pbuf_free(ptr);

      /* Update tcp window size to be advertized : should be called when received
      data (with the amount plen) has been processed by the application layer */
      tcp_recved(tpcb, plen);
   }
   else if(wr_err == ERR_MEM)
   {
      /* we are low on memory, try later / harder, defer to poll */
     es->p = ptr;
   }
   else
   {
     /* other problem ?? */
   }
  }
}

/**
  * @brief  This functions closes the tcp connection
  * @param  tcp_pcb: pointer on the tcp connection
  * @param  es: pointer on echo_state structure
  * @retval None
  */
static void tcp_raw_connection_close(struct tcp_pcb *tpcb, struct tcp_raw_struct *es)
{

  /* remove all callbacks */
  tcp_arg(tpcb, NULL);
  tcp_sent(tpcb, NULL);
  tcp_recv(tpcb, NULL);
  tcp_err(tpcb, NULL);
  tcp_poll(tpcb, NULL, 0);

  /* delete es structure */
  if (es != NULL)
  {
    mem_free(es);
  }

  /* close tcp connection */
  tcp_close(tpcb);
}


