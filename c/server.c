#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

static void Data_handle(void *sock_fd);
int main(int argc, char **argv)
{
     int sockfd_server;
     int sockfd;
     int fd_temp;
     struct sockaddr_in s_addr_in;
     struct sockaddr_in s_addr_client;
     int client_length;

     sockfd_server = socket(AF_INET, SOCK_STREAM, 0);
     assert(sockfd_server != -1);

     memset(&s_addr_in, 0, sizeof(s_addr_in));
     s_addr_in.sin_family = AF_INET;
     s_addr_in.sin_addr.s_addr = htonl(INADDR_ANY);
     s_addr_in.sin_port = htons(10086);
     fd_temp = bind(sockfd_server, (struct sockaddr *)(&s_addr_in), sizeof(s_addr_in));
     if(fd_temp == -1)
     {
	  printf("bind error");
	  return -1;
     }

     fd_temp = listen(sockfd_server, 512);
     if(fd_temp == -1)
     {
	  printf("listen error");
	  return -1;
     }
     
     while(1)
     {
	  printf("waiting for new connection...\n");
	  pthread_t thread_id;
	  client_length = sizeof(s_addr_client);
	  
	  sockfd = accept(sockfd_server, (struct sockaddr *)(&s_addr_client), (socklen_t *)(&client_length));
	  if(sockfd == -1)
	  {
	       printf("accept error");
	       continue;
	  }
	  printf("a new connection occurs!\n");
	  if(pthread_create(&thread_id, NULL, (void *)(&Data_handle), (void *)(&sockfd)) == -1)
	  {
	       printf("pthread create error!\n");
	       break;
	  }
     }
     int ret =  shutdown(sockfd_server, SHUT_WR);
     assert(ret != -1);
     printf("server shuts down\n");
     return 0;
}

static void Data_handle(void *sock_fd)
{
     int fd = *(int *)sock_fd;
     int i_recevBytes;
     char data_recv[1024];
     const char * data_send = "Server has received your request!\n";
     
     while(1)
     {
	  printf("waiting for request...\n");
	  memset(data_recv, 0, 1024);
	  i_recevBytes = read(fd, data_recv, 1024);
	  if(i_recevBytes == 0)
	  {
	       printf("Maybe the client has closed\n");
	       break;
	  }
	  if(i_recevBytes == -1)
	  {
	       printf("read error\n");
	       break;
	  }
	  if(strcmp(data_recv, "quit") == 0)
	  {
	       printf("Quit command!\n");
	       break;
	  }
	  printf("read from client: %s\n", data_recv);
	  if(write(fd, data_send, strlen(data_send)) == -1)
	       break;
     }
     printf("terminating current client connection...\n");
     close(fd);
     pthread_exit(NULL);
}
