#include "Butter_server.h"
#include <asm-generic/errno-base.h>
#include <netdb.h>
#include <stdio.h>
#include <sys/socket.h>



int butter_start_serv(const char *port, int family,int protocol,int* fd){
    struct addrinfo hints;
    memset(&hints,0,sizeof(struct addrinfo));
    hints.ai_family = family ? (family > 1 ? AF_INET6 :AF_INET): AF_UNSPEC;
    hints.ai_socktype = protocol ? SOCK_DGRAM : SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    struct addrinfo* bindaddr;
    if (getaddrinfo(NULL, port, &hints, &bindaddr)){
        fprintf(stderr,"service translation failed ..\n");
        freeaddrinfo(bindaddr);
        return 1;
    }
    int server = socket(bindaddr->ai_family, bindaddr->ai_socktype, bindaddr->ai_protocol); 
    if(server < 0){
        fprintf(stderr,"Creating a socket failed .. ");
        freeaddrinfo(bindaddr);
        return 1;
    }
    if(bind(server, bindaddr->ai_addr, bindaddr->ai_addrlen)){
        fprintf(stderr,"socket binding failed.. \n");
        close(server);
        freeaddrinfo(bindaddr);
        return 1;
    }
    freeaddrinfo(bindaddr);
    *fd = server;
    return 0;
}

int butter_listen(int *fd, int backlog){
    if (listen(*fd, backlog) < 0){
        perror("listen failed");
        return -1;
    }
    return 0;
}

int butter_pop_client(int *fd){
    struct sockaddr_storage clientaddr;
    socklen_t len = sizeof(clientaddr);

    int client = accept(*fd, (struct sockaddr*)&clientaddr, &len);
    if(client < 0){
        perror("accept failed");
        return -1;
    }
    return client;
}
