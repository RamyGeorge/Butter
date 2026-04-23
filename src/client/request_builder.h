#include "../Socket_headers.h"
#include "../structures.h"


struct butter_request* butter_initiate_req(const char* domain,const char* endpoint);
struct butter_request* butter_req_method(struct butter_request* br, char* method);
struct butter_request* butter_req_parameter(struct butter_request* br);
