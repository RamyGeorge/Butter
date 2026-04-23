#include "Socket_headers.h"

#define CHUNK_SIZE 4096


struct butter_request{
    char method[8];
    char url[2048];
    char ver[16];
    char body[4096];
};

struct butter_response{
    int status;
    char content_type[64];
    size_t content_length;
};
