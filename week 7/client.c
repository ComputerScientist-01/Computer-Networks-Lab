#include "string.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "netdb.h"
#include "arpa/inet.h"
int main()
{
int socketDescriptor;
struct sockaddr_in serverAddress;
char sendBuffer[8000],recvBuffer[8000];
pid_t cpid;
bzero(&serverAddress,sizeof(serverAddress));
serverAddress.sin_family=AF_INET;
serverAddress.sin_addr.s_addr=inet_addr("127.0.0.1");
serverAddress.sin_port=htons(5555);
socketDescriptor=socket(AF_INET,SOCK_STREAM,0);
connect(socketDescriptor,(struct sockaddr*)&serverAddress,sizeof(serverAddress));
cpid=fork();
if(cpid==0)
{
while(1)
{
bzero(&sendBuffer,sizeof(sendBuffer));
printf("\nType a message here ... ");
fgets(sendBuffer,80000,stdin);
send(socketDescriptor,sendBuffer,strlen(sendBuffer)+1,0);
printf("\nMessage sent !\n");
} }
else
{
while(1)
{
bzero(&recvBuffer,sizeof(recvBuffer));
recv(socketDescriptor,recvBuffer,sizeof(recvBuffer),0);
printf("\nSERVER : %s\n",recvBuffer);
} }
return 0;
}
