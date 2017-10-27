#include <iostream>

template<class T>
class factory
{
public:
  factory();
  static T* getInstance();
};
