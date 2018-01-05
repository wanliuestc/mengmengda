#include <iostream>

void test(int *a)
{
     *a = 10;
}

void test2(int &a)
{
     a = 10;
}

int main(void)
{
     int i = 100;
     test2(i);
     return 0;
}
