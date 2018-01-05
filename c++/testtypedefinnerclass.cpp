#include <iostream>
using namespace std;

class T;

class O
{
public:
     void test(T *t);
};

class T
{
public:
     typedef std::string::size_type pos;
     friend void O::test(T *);
private:
     pos cursor = 0;
     pos height = 0, width = 0;
     std::string contents;
};

void O::test(T *t)
{
     cout << t->cursor << endl;
}

int main(void)
{
     T t;
     O o;
     o.test(&t);
     return 0;
}
