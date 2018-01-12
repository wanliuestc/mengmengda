#include <stdio.h>

int main(void)
{
   int i = 10;
   *(&i) = 100;
   printf("%d\n", i);
   return 0;
}
