
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __ZEPHYR__

#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#else

#include <net/socket.h>
#include <kernel.h>

#endif

#include <errno.h>
#include <unistd.h>

#include "scpi/scpi.h"
#include "scpi-def.h"

int clifd;

size_t SCPI_Write(scpi_t * context, const char * data, size_t len) {
    (void) context;

    if (context->user_context != NULL) 
    {
 	    return send(clifd, data, len, 0);
    }
       return 0;
}

static int createServer(int port) {
    int fd;
    int rc;
    int on = 1;
    struct sockaddr_in servaddr;

    /* Configure TCP Server */
    memset(&servaddr, 0, sizeof (servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    /* Create socket */
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
       // perror("socket() failed");
        exit(-1);
    }

    /* Set address reuse enable */
    rc = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof (on));
    if (rc < 0) {
      //  perror("setsockopt() failed");
        close(fd);
        exit(-1);
    }

      /* Bind to socket */
    rc = bind(fd, (struct sockaddr *) &servaddr, sizeof (servaddr));
    if (rc < 0) {
      //  perror("bind() failed");
        close(fd);
        exit(-1);
    }

    /* Listen on socket */
    listen(fd, 1);
    if (rc < 0) {
      //  perror("listen() failed");
        close(fd);
        exit(-1);
    }

    return fd;
}

static int waitServer(int fd) {
    fd_set fds;
    struct timeval timeout;
    int rc;
    int max_fd;

    FD_ZERO(&fds);
    max_fd = fd;
    FD_SET(fd, &fds);

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    rc = select(max_fd + 1, &fds, NULL, NULL, &timeout);

    return rc;
}

/*
 *
 */
int main(void) {
  int rc;

    int listenfd;
    char smbuffer[10];

    /* user_context will be pointer to socket */
    scpi_context.user_context = NULL;

    SCPI_Init(&scpi_context,
            scpi_commands,
            &scpi_interface,
            scpi_units_def,
            SCPI_IDN1, SCPI_IDN2, SCPI_IDN3, SCPI_IDN4,
            scpi_input_buffer, SCPI_INPUT_BUFFER_LENGTH,
            scpi_error_queue_data, SCPI_ERROR_QUEUE_SIZE);

    listenfd = createServer(5025);

    while (1) {
     //   int clifd;
        struct sockaddr_in cliaddr;
       socklen_t clilen;

        clilen = sizeof (cliaddr);
        clifd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);

        if (clifd < 0) continue;

       // printf("Connection established %s\r\n", inet_ntoa(cliaddr.sin_addr));

        scpi_context.user_context = &clifd;

        while (1) {
            rc = waitServer(clifd);
            if (rc < 0) { /* failed */
           //     perror("  recv() failed");
                break;
            }
            if (rc == 0) { /* timeout */
                SCPI_Input(&scpi_context, NULL, 0);
            }
            if (rc > 0) { /* something to read */
                rc = recv(clifd, smbuffer, sizeof (smbuffer), 0);
                if (rc < 0) {
                    if (errno != EWOULDBLOCK) {
                      //  perror("  recv() failed");
                        break;
                    }
                } else if (rc == 0) {
                //    printf("Connection closed\r\n");
                    break;
                } else {
                    SCPI_Input(&scpi_context, smbuffer, rc);
                }
            }
        }

        close(clifd);
    }

    return (EXIT_SUCCESS);
}

