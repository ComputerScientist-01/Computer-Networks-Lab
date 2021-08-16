#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sd;
    char buff[1024];
    struct sockaddr_in servaddr;
    socklen_t len;
    len = sizeof(servaddr);

    /*UDP socket is created, an Internet socket address structure is filled with                 
    wildcard address & server’s well  known port*/
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sd < 0)
    {
        perror("Cannot open socket");
        exit(1);
    }
    bzero(&servaddr, len);

    /*Socket address structure*/
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(5669);
    while (1)
    {
        printf("Enter Input data : \n");
        bzero(buff, sizeof(buff));

        /*Reads the message from standard input*/
        fgets(buff, sizeof(buff), stdin);

        /*sendto is used to transmit the request message to the server*/
        if (sendto(sd, buff, sizeof(buff), 0, (struct sockaddr *)&servaddr, len) < 0)
        {
            perror("Cannot send data");
            exit(1);
        }
        printf("Data sent to UDP Server:%s", buff);
        bzero(buff, sizeof(buff));
        /*Receiving the echoed message from server*/
        if (recvfrom(sd, buff, sizeof(buff), 0, (struct sockaddr *)&servaddr, &len) < 0)
        {
            perror("Cannot receive data");
            exit(1);
        }
        printf("Received Data from server: %s", buff);
    }
    close(sd);
    return 0;
}