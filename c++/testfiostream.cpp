#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main(void)
{
     char buf[1024];
     ifstream in;
     ofstream out;
     int len;
     in.open("222", fstream::in | fstream::binary);
     out.open("111", fstream::out| fstream::binary);
     while(in)
     {
	  in.read(buf, 1024);
	  len = in.gcount();
	  out.write(buf, len);
	  memset(buf, 0, 1024);
     }
     in.close();
     out.close();
     return 0;
}
