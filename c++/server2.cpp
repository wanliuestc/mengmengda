#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <map>
#include <stdio.h>

using namespace std;

class test
{
public:
     int t;
};
class MSG
{
public:
     unsigned int id;
     char buf[1024];
     unsigned int len;
};

class MESSAGE 
{
public:
     in_addr_t s_addr;
     MSG m;
     unsigned long size;
};

static void* Data_handle(void *sock_fd);

map<in_addr_t, int> socketMap;

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
     s_addr_in.sin_port = htons(10088);
     fd_temp = bind(sockfd_server, (struct sockaddr *)(&s_addr_in), sizeof(s_addr_in));
     if(fd_temp == -1)
     {
	  cout << "bind error" << endl;
	  return -1;
     }

     fd_temp = listen(sockfd_server, 512);
     if(fd_temp == -1)
     {
	  cout << "listen error" << endl;
	  return -1;
     }
     
     while(1)
     {
	  cout << "waiting for new connection..." << endl;
	  pthread_t thread_id;
	  client_length = sizeof(s_addr_client);
	  
	  sockfd = accept(sockfd_server, (struct sockaddr *)(&s_addr_client), (socklen_t *)(&client_length));
	  if(sockfd == -1)
	  {
	       cout << "accept error" << endl;
	       continue;
	  }
	  cout << "a new connection occurs!" << endl;
	  socketMap[s_addr_client.sin_addr.s_addr] = sockfd;
	  if(pthread_create(&thread_id, NULL, &Data_handle, (void *)(&sockfd)) == -1)
	  {
	       cout << "pthread create error!" << endl;
	       break;
	  }
     }
     int ret =  shutdown(sockfd_server, SHUT_WR);
     assert(ret != -1);
     cout << "server shuts down" << endl;
     return 0;
}

static void* Data_handle(void *sock_fd)
{
     int fd = *(int *)sock_fd;
     int i_recevBytes;
     MESSAGE msg;
     const char * data_send = "Server has received your request!\n";
     //FILE *fp = fopen("file", "wb");
     /*if(!fp)
     {
	  printf("open file error");
	  pthread_exit(NULL);
	  }*/
     while(1)
     {
	  memset(&msg, 0, sizeof(MESSAGE));
	  i_recevBytes = read(fd, &msg, sizeof(MESSAGE));
	  if(i_recevBytes <= 0)
	       break;
	  while(i_recevBytes < 1048)
	  {
	       int temp = read(fd, (char *)&msg + i_recevBytes, sizeof(MESSAGE) - i_recevBytes);
	       i_recevBytes += temp;
	  }
	  //fseek(fp, 1024*msg.m.id, SEEK_SET);
	  //fwrite(msg.m.buf, 1, msg.m.len, fp);
	  cout << msg.m.id << "  " << msg.m.len << endl;
	  int remotesock = socketMap[msg.s_addr];
	  write(remotesock, &msg, sizeof(MESSAGE));
     }
     //fclose(fp);
     cout << "terminating current client connection..." << endl;
     close(fd);
     pthread_exit(NULL);
}
