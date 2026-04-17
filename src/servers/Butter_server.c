#include "Butter_server.h"
#include <asm-generic/errno-base.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

const char* methods[9] = {"GET","POST","DELETE","PUT","OPTIONS","PATCH","HEAD","CONNECT","TRACE"};

/* Todo: add support for udp connection */
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

int butter_parse_request(const char *req, struct butter_request *butterreq){

    for(int i =0; i <9;i++){
        char* tmp;
        if((tmp = strstr(req,methods[i])) != NULL){
            strcpy(butterreq->method, methods[i]);
            break;
        }
    }

    // primitive approach but it's all i have. start a pointer after method and parse all the way 1 before pointer for ver
    const char * verptr = strstr(req,"HTTP/1.1");
    const char * textpr = strstr(req,"/");
    
    int idx = 0;
    while(textpr != verptr-1){
        char c = *textpr;
        strcpy(&butterreq->path[idx], &c);
        idx++;
        textpr++;
    }

    // int newidx = 0;
    // char *newline = strstr(req, "\n");
    // while(verptr != newline){
    //     strcpy(&butterreq->ver[newidx],&req[idx]);
    //     verptr++;
    //     newidx++;
    //     idx++;
    // }


    return 1;



}
