#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

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
     fstream in;
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
     in.open("222", fstream::in|fstream::binary);
     if(in.rdstate() == fstream::failbit)
     {
	  cout << "file opened failed" << endl;
	  return -1;
     }

     in.seekg(0, fstream::end);
     long size = in.tellg();
     in.seekg(0, fstream::beg);

     int id = 0;
     int len = 0;
     while(in)
     {
	  in.read(data_send, 1024);
	  len = in.gcount();
	  MESSAGE m;
	  //cout << "read file " << len << " " << id << " " << in.tellg() << endl;
	  m.s_addr = inet_addr("172.20.156.181");
	  m.m.id = id;
	  m.m.len = len;
	  memcpy(m.m.buf, data_send, len);
	  m.size = size;
	  write(sockfd, &m, sizeof(MESSAGE));
	  memset(data_send, 0, 1024);
	  cout << m.m.id << "  " << m.m.len << endl;
	  ++id;
     }
     in.close();
     while(1);
     int ret = shutdown(sockfd, SHUT_WR);
     assert(ret != -1);
     return 0;
}
