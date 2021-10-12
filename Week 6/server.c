#include<sys/types.h>
#include<stdio.h>
#include<netdb.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
int main(int argc,char *argv[])
{
int n,sd,ad;
struct sockaddr_in servaddr,cliaddr;
socklen_t clilen,servlen;
char buff[10000],buff1[10000];
bzero(&servaddr,sizeof(servaddr));
 /*Socket address structure*/ 
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(5000);
 /*TCP socket is created, an Internet socket address structure is filled with 
wildcard address & server’s well known port*/ 
sd=socket(AF_INET,SOCK_STREAM,0);
/*Bind function assigns a local protocol address to the socket*/
bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
/*Listen function specifies the maximum number of connections that kernel 
should queue for this socket*/
listen(sd,5);
printf("%s\n","server is running…");
/*The server to return the next completed connection from the front of the 
 completed connection Queue calls it*/
ad=accept(sd,(struct sockaddr*)&cliaddr,&clilen);
while(1)
{
bzero(&buff,sizeof(buff));
/*Receiving the request from client*/
recv(ad,buff,sizeof(buff),0);
printf("Receive from the client:%s\n",buff);
n=1;
while(n==1)
{
bzero(&buff1,sizeof(buff1));
printf("%s\n","Enter the input data:");
/*Read the message from client*/
fgets(buff1,10000,stdin);
/*Sends the message to client*/
send(ad,buff1,strlen(buff1)+1,0);
printf("%s\n","Data sent");
n=n+1;
}
}
return 0;
}
