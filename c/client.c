#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
     int sockfd;
     int tempfd;
     struct sockaddr_in s_addr_in;
     char data_send[1024];
     char data_recv[1024];
     memset(data_send, 0, 1024);
     memset(data_recv, 0, 1024);

     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if(sockfd == -1)
     {
	  printf("socket error!\n");
	  return -1;
     }

     memset(&s_addr_in, 0, sizeof(s_addr_in));
     s_addr_in.sin_family = AF_INET;
     s_addr_in.sin_addr.s_addr = inet_addr("127.0.0.1");
     s_addr_in.sin_port = htons(10086);

     tempfd = connect(sockfd, (struct sockaddr *)(&s_addr_in), sizeof(s_addr_in));
     if(tempfd == -1)
     {
	  printf("Connect error\n");
	  return -1;
     }

     while(1)
     {
	  printf("please input ...\n");
	  gets(data_send);
	  tempfd = write(sockfd, data_send, 1024);
	  if(tempfd == -1)
	  {
	       printf("write error\n");
	       exit(0);
	  }
	  if(strcmp(data_send, "quit") == 0)
	       break;
	  else
	  {
	       tempfd = read(sockfd, data_recv, 1024);
	       assert(tempfd != -1);
	       printf("%s\n", data_recv);
	       memset(data_send, 0, 1024);
	       memset(data_recv, 0, 1024);
	  }
     }
     int ret = shutdown(sockfd, SHUT_WR);
     assert(ret != -1);
     return 0;
}
