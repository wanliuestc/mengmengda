#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(void)
{
     void exceptionhandler(int);
     signal(SIGFPE, exceptionhandler);
     int zero = 0;
     int t = 100 / zero;
     return 0;
}

void exceptionhandler(int arg)
{
     printf("error %d\n", arg);
     exit(1);
}
