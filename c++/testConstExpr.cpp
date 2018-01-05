#include <iostream>

constexpr int new_sz()
{
     return 42;
}

constexpr size_t scale(size_t cnt)
{
     return new_sz() * cnt;
}

int main(void)
{
     int i;
     int arr[new_sz()];
     int arr2[scale(3)];
     int arr3[scale(i)];
     int arr4[i];
     return 0;
}
