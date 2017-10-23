#include <stdio.h>
int main(void)
{
     unsigned long l = 100;
     int a = -1;
     long result = l + (unsigned long)a;
     printf("%ld\n", result);
     //printf("%*.3d\n", 1000, 12222);
     printf("%.3d", 10000);
     printf("%2.3s\n", "aaaaaa");
     return 0;
}
