#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
int main(int argc, char *argv[])
{
    int sd, ad;
    char buff[1024];
    struct sockaddr_in servaddr, cliaddr;
    //socklen_t clilen=sizeof(cliaddr);
    time_t t1;
    bzero(&servaddr, sizeof(servaddr));
    /*Socket address structure*/
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(1507);
    /*TCP socket is created, an Internet socket address structure is filled with
wildcard address & server’s well known port*/
    sd = socket(AF_INET, SOCK_STREAM, 0);
    /*Bind function assigns a local protocol address to the socket*/
    bind(sd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    /*Listen function specifies the maximum number of connections that kernel should queue
for this socket*/
    listen(sd, 5);
    printf("Server is running…\n");
    /*The server to return the next completed connection from the front of the
completed connection Queue calls it*/
    ad = accept(sd, (struct sockaddr *)NULL, NULL);
    while (1)
    {
        bzero(&buff, sizeof(buff));
        /*Library function time returns the Coordinated Universal Time*/
        t1 = time(NULL);
        /*Prints the converted string format*/
        snprintf(buff, sizeof(buff), "%24s\r\n", ctime(&t1));
        send(ad, buff, sizeof(buff), 0);
    }
}