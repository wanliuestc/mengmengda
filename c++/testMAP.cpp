#include <iostream>
#include <map>
#include <utility>
#include <string>

using namespace std;


int main(void)
{
   map<string, string> m;
   m.insert(make_pair("hello", "world"));
   m.insert({"test", "123"});
   m.insert(pair<string, string>("aaa", "nnn"));

   for(map<string, string>::iterator ite = m.begin(); ite != m.end(); ite++)
      cout << ite->first << "  " << ite->second << endl;

   pair<map<string, string>::iterator, bool> re = m.insert({"aaaa", "bbb"});
   cout << re.first->first << " " << re.first->second << "  " << re.second << endl;

   return 0;
}
