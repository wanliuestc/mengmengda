#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class test
{
public:
     int a;
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

int main(void)
{
     FILE *fp;
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
	  cout << "socket error!" << endl;
	  return -1;
     }

     memset(&s_addr_in, 0, sizeof(s_addr_in));
     s_addr_in.sin_family = AF_INET;
     s_addr_in.sin_addr.s_addr = inet_addr("172.20.110.115");
     s_addr_in.sin_port = htons(10088);

     tempfd = connect(sockfd, (struct sockaddr *)(&s_addr_in), sizeof(s_addr_in));
     if(tempfd == -1)
     {
	  cout << "Connect error" << endl;
	  return -1;
     }
     fp = fopen("666", "wb");
     if(!fp)
     {
	  printf("open file error");
	  return -1;
     }
     int id = 0;
     int len = 0;
     int received = 0;
     MESSAGE mg;
     while(1)
     {
	  memset(&mg, 0, sizeof(MESSAGE));
	  received = read(sockfd, &mg, sizeof(MESSAGE));
	  if(received <= 0)
	       break;
	  while(received < 1048)
	  {
	       int temp = read(fd, (char *)&msg + i_recevBytes, sizeof(MESSAGE) - i_recevBytes);
	       i_recevBytes += temp;
	  }
	  fseek(fp, 1024*msg.m.id, SEEK_SET);
	  fwrite(msg.m.buf, 1, msg.m.len, fp);
     }
     fclose(fp);
     while(1)
     int ret = shutdown(sockfd, SHUT_WR);
     assert(ret != -1);
     return 0;
}
