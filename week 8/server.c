#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
int sd, ad, size;
struct sockaddr_in servaddr, cliaddr;
socklen_t clilen;
clilen = sizeof(cliaddr);
struct stat x;
char buff[100], file[10000];
FILE *fp;
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(7777);
sd = socket(AF_INET, SOCK_STREAM, 0);
bind(sd, (struct sockaddr *)&servaddr, sizeof(servaddr));
listen(sd, 5);
printf("%s\n", "Server Is Running....");
ad = accept(sd, (struct sockaddr *)&cliaddr, &clilen);
while (1)
{
bzero(buff, sizeof(buff));
bzero(file, sizeof(file));
recv(ad, buff, sizeof(buff), 0);
fp = fopen(buff, "r");
stat(buff, &x);
size = x.st_size;
fread(file, sizeof(file), 1, fp);
printf("Contents of File:\n%s", file);
send(ad, file, sizeof(file), 0);
}
return 0;
}
