Welcome to Butter!
I Have made this tiny library with two intentions in mind. First, Getting familiar with socket programming.Second, Providing relevant abstractions that facilitate network programming 

If you find it of any use by all means i'd love for you to test it out and give any feedback / issues you faced

Without further ado, here is the documentation


``Butter Server``
Butter server provides all necessary operations for the server side

- butter_start_serv(const char *port, int family,int protocol,int* fd)
This is the first step to any server you wish to start. It takes the following:
port: String
family: 0-> unspecified , 1->ipv4, 2->ipv6
protocol: 0->tcp, 1->udp
*fd : an output parameter that will be set to a value if function return successfully (This will serve as the server socket internally)
return value : 1 on failure, 0 on success

- butter_listen(int* fd,int backlog)
After setting up the socket, This function starts listening on passed socket (fd), backlog defines number of queued up connections you are willing to put on said queue with a max of 128

- butter_pop_client(int* fd)
pops one client out of the ones queued up from the listen queue 
it returns a new socket for that client as an int

- butter_parse_request(const char* req,struct butter_request* butterreq);
This function parses any incoming request and has butter_request* as a output parameter
butter_request is simple all relevant info for any given request
method: GET,POST,DELETE etc
ver: HTTP/1.1 , HTTP/3 etc
path: endpoint called
body: request body
returns zero on success

- butter_on