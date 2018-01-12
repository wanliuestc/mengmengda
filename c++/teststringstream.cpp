#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(void)
{
   string t = "aaa  bbb 12  12.5";
   string a, b;
   int c;
   double d;
   istringstream s(t);
   s >> a >> b >> c >> d;
   cout << a << " " << b << " " << c << " " << d << endl;
   return 0;
}
