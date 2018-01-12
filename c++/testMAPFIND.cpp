#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main(void)
{
   multimap<string, string> m;
   m.insert({"changwanli", "aaa"});
   m.insert({"helllo", "bbb"});
   m.insert({"changwanli", "bbb"});
   m.insert({"changwanli", "ccc"});
   
   map<string, string>::iterator ite = m.find("changwanli");
   cout << ite->second << endl;
   cout << (++ite)->second << endl;
   return 0;
}
