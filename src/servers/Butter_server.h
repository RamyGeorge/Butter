#include "../Socket_headers.h"
#include <stddef.h>
#include <stdio.h>


int butter_start_serv(const char* port,int family,int protocol,int* fd);
int butter_listen(int* fd,int backlog);
int butter_pop_client(int *fd);
// int butter_parse_request(const char* req,struct butter_request* butterreq);
// int butter_handle_request(struct butter_request* butterreq);
// int butter_on(int fd,struct butter_request* butterreq, FILE *fp);