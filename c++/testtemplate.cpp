#include "testtemplate.h"
#include "test.cpp"

template<class T>
factory<T>::factory()
{
  
}

template<class T>
T* factory<T>::getInstance()
{
  return new T();
}

int main(void)
{
  test *t = factory<test>::getInstance();
  return 0;
}
