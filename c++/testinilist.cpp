#include <iostream>
#include <list>
#include <string>
#include <array>

using namespace std;

int main(void)
{
   list<string> l = {"aaa", "bbb", "ccc"};
   array<string, 5> arr = {"hello", "world"};
   l = {"ddd", "eee"};
   arr = {"eee", "ggg"};
   cout << l.size() << "  " << arr.size() << endl;
   return 0;
}
