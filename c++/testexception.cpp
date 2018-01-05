#include <iostream>
#include <stdexcept>

int throwfunction(int i)
{
     if(i < 0)
	  throw std::runtime_error("input error");
     else
	  return 0;
}

int main(void)
{
     try
     {
	  throwfunction(-1);
     }
     catch(std::runtime_error err)
     {
	  std::cout << "error " << err.what()  << std::endl;
     }
     return 0;
}
