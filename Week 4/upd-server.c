#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
    int sd;
    char buff[1024];
    struct sockaddr_in cliaddr, servaddr;
    socklen_t clilen;
    clilen = sizeof(cliaddr);

    /*UDP socket is created, an Internet socket address structure is filled with               wildcard address & server’s well known port*/
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sd < 0)
    {
        perror("Cannot open Socket");
        exit(1);
    }
    bzero(&servaddr, sizeof(servaddr));
    /*Socket address structure*/
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(5669);

    /*Bind function assigns a local protocol address to the socket*/
    if (bind(sd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("error in binding the port");
        exit(1);
    }
    printf("%s", "Server is Running…\n");
    while (1)
    {
        bzero(&buff, sizeof(buff));

        /*Read the message from the client*/
        if (recvfrom(sd, buff, sizeof(buff), 0, (struct sockaddr *)&cliaddr, &clilen) < 0)
        {
            perror("Cannot rec data");
            exit(1);
        }
        printf("Message is received \n", buff);

        /*Sendto function is used to echo the message from server to client side*/
        if (sendto(sd, buff, sizeof(buff), 0, (struct sockadddr *)&cliaddr, clilen) < 0)
        {
            perror("Cannot send data to client");
            exit(1);
        }
        printf("Send data to UDP Client: %s", buff);
    }
    close(sd);
    return 0;