#include <iostream>

int main()
{
  int capacity = 10;
  char * str = new char[capacity]();
  int i = 0;
  while ((std::cin >> str[i]) && (i < capacity))
  {
    ++i;
  }
  delete[] str;
}
