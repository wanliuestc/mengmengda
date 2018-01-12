#include <iostream>

using namespace std;

int main(void)
{
   char t;
   char a[10] = {};
   ios_base::fmtflags f = std::cout.flags();
   cout << f << endl;
   cout << 256 << endl;
   cout.flags(ostream::hex | ostream::showbase);
   cout << 256 << endl;
   cout.flags(ostream::hex | ostream::showbase | ostream::right);
   cout.width(10);
   cout.fill('_');
   cout << 0x100 << endl;
   cin.get(t);
   cout << t << endl;
   cin.get(a, 10, ',');
   cout << a << endl;
   return 0;
}
