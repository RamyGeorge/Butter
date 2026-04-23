#include "client.h"
#include "../Socket_headers.h"
#include <netdb.h>
#include <stdio.h>
#include <sys/socket.h>



int butter_create_client(const char* domain, const char* port, int protocol) {
    // todo: Handle UDP connections
    struct addrinfo hints = {0};
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = protocol ? SOCK_DGRAM : SOCK_STREAM;

    struct addrinfo *peer;
    int status = getaddrinfo(domain, port, &hints, &peer);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return -1;
    }
    int peersock;
    struct addrinfo *p;
    for (p = peer; p != NULL; p = p->ai_next) {
        peersock = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (peersock < 0) continue;
        if (connect(peersock, p->ai_addr, p->ai_addrlen) == 0) {
            break;
        }
        close(peersock);
    }
    freeaddrinfo(peer);
    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        return -1;
    }

    return peersock;
}