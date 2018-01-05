#include <iostream>

class A
{
public:
     int b;
};

class Test
{
public:
     void test(int i)
     {
	  std::cout << i << std::endl;
     }
     void test2(int i) const
     {
	  std::cout << i << std::endl;
     }
     int *p;
     int t;
     A a;
};

void test3(A &a)
{
     std::cout << a.b << std::endl;
}

int main(void)
{
     Test t;
     A a;
     a.b = 5;
     t.test2(1);
     std::cout << t.t << " " << t.p << " " << t.a.b << std::endl;
     test3(a);
     return 0;
}
