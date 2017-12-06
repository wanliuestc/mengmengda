#include <iostream>

using namespace std;

int main(void)
{
     int arr[3][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}};
     //for(int (&row)[5] : arr)
     //for(int col : row)
     //cout << col << endl;
     int (*row)[5] = arr; 
     for(int i = 0; i < 3; i++)
	  for(int j = 0; j < 5; j++)
	       cout << *(*(row + i) + j) << endl;
     return 0;
}
