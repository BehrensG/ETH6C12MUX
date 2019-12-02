/*
 * echo.h
 *
 *  Created on: Dec 1, 2019
 *      Author: grzegorz
 */

#ifndef INC_TCP_RAW_H_
#define INC_TCP_RAW_H_

#include "lwip/pbuf.h"

struct echo_state
{
    unsigned char state;
    unsigned char  retries;
    struct tcp_pcb *pcb;
    // pbuf (chain) to recycle
    struct pbuf *p;
};

/* structure for maintaing connection infos to be passed as argument
   to LwIP callbacks*/
struct tcp_raw_struct
{
  uint8_t state;             /* current connection state */
  struct tcp_pcb *pcb;    /* pointer on the current tcp_pcb */
  struct pbuf *p;         /* pointer on the received/to be transmitted pbuf */
};


void tcp_raw_init(void);
void tcp_raw_send(struct tcp_pcb *tpcb, struct tcp_raw_struct *es);
err_t tcp_raw_sent(void *arg, struct tcp_pcb *tpcb, uint16_t len);

#endif /* INC_TCP_RAW_H_ */
