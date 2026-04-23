#include "request_builder.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

const char* reqmethods[9] = {"GET","POST","DELETE","PUT","OPTIONS","PATCH","HEAD","CONNECT","TRACE"};

struct butter_request* butter_initiate_req(const char* domain,const char* endpoint){ // option for HTTPS over HTTP?
    struct butter_request* bq = malloc(sizeof(struct butter_request));
    memset(bq, 0, sizeof(struct butter_request));
    char url[2048];
    int n = snprintf(url, sizeof(url), "http://%s%s", domain, endpoint);
    if (n < 0 || n >= (int)sizeof(url)) {
        free(bq);
        return NULL;
    }
    printf("initialized URL with : %s",url);

    strncpy(bq->url, url, sizeof(bq->url) - 1);
    bq->url[sizeof(bq->url) - 1] = '\0';
    return bq;
}

struct butter_request* butter_req_method(struct butter_request* br, char* method){
    char methodupper[8] = {0};
    char* iterator = method;
    int idx =0;
    while(*iterator != '\0' && idx < 8){
        methodupper[idx] = toupper(*iterator);
        iterator++;
        idx++;
    }
    int r = 0;
    for(int i =0; i < 9;i++){
        if(strcmp(methodupper, reqmethods[i]) == 0){
            r = 1;
            break;
        }
    }
    if(r){
        strncpy(br->method, methodupper, sizeof(br->method));
    }else{
        printf("Invalid request method..");
    }
    return br;

}