#include "../Socket_headers.h"


int butter_start_serv(const char* port,int family,int protocol,int* fd);
int butter_listen(int* fd,int backlog);
int butter_pop_client(int *fd);