#include "changeString.hpp"

const int size = 16;
int main()
{
  using namespace novokhatskiy;
  char* buffer = nullptr;
  int result = 0;
  try
  {
    buffer = new char[size];
    std::cin.getline(buffer, size);
    if (!std::cin)
    {
      std::cerr << "Can't read the string\n";
      result = 1;
      return 1;
    }
    else
    {
      buffer = changeString(buffer, buffer);
      std::cout << buffer << "\n";
    }
  }
  catch (const std::bad_alloc &e)
  {
    throw e;
    result = 1;
  }
  delete[] buffer;
  return result;
}

