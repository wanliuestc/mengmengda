#include <iostream>

class A
{
public:
     static int a;
     static const int period;
//     int arr[period];

public:
     A()
     {
	  std::cout << "in a construtor" << std::endl;
     }
};
int A::a = 10;
int A::period = 100;
void test(const int &a)
{
     std::cout << a << std::endl;
}

int main(void)
{
     //A a;
     test(A::a);
     return 0;
}
