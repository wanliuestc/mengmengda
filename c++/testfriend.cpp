#include <iostream>
#include <string>

using namespace std;

class T
{
private:
     int a;
     string s;
     friend void testfriend(T *);
     friend class O;
public:
     T():a(0),s("hello"){}
};

class O
{
};

void testfriend(T *t)
{
     cout << t->a <<  " " << t->s << endl;
}

int main(void)
{
     T *t = new T();
     testfriend(t);
     delete t;
     return 0;
}
