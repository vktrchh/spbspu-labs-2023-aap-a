#include <cctype>
#include <iostream>

const int size = 16;
int main()
{
  char* buffer = nullptr;
  try
  {
    buffer = new char[size];
    std::cin.getline(buffer, size);
    if (!std::cin)
    {
      std::cerr << "Can't read the string\n";
      return 1;
    }
    else
    {
      std::cout << changeString(buffer. buffer);
    }
  }
  catch (const std::bad_alloc &e)
  {
    throw e;
  }
}

