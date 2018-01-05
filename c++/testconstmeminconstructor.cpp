#include <iostream>

class B
{
public:
     int b;
public:
     B()
     {
	  std::cout << "in b constructor" << std::endl;
     }
     B(int a){
	  this->b = a;
	  std::cout << "in b param constructor" << std::endl;
     }
};

class A
{
public:
     const int i;
     B b;
public:
     A();
     /*A():i(10)
     {
	  //i = 10;
	  }*/
};


A::A():i(10)//,b(new B())
{
     std::cout << "in a constructor" << std::endl;
     b = B(3);
}

int main(void)
{
     A a;
     return 0;
}
