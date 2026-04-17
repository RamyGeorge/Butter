#include "../Socket_headers.h"
#include <stddef.h>
#include <stdio.h>

struct butter_request{
    char method[8];
    char path[512];
    char ver[16];
    char body[4096];
};

struct butter_response{
    int status;
    char content_type[64];
    size_t content_length;
};


int butter_start_serv(const char* port,int family,int protocol,int* fd);
int butter_listen(int* fd,int backlog);
int butter_pop_client(int *fd);
int butter_parse_request(const char* req,struct butter_request* butterreq);
int butter_handle_request(struct butter_request* butterreq);
int butter_on(int fd,struct butter_request* butterreq, FILE *fp);