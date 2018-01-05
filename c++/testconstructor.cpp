#include <iostream>
#include <string>

class T
{
public:
     int a;
     std::string s;

public:
     T(std::string &s):s(s)
     {
	 
     }
};

int main(void)
{
     std::string s = "abc";
      T t(s);
     std::cout << t.a << " " << t.s << std::endl;
     return 0;
}
