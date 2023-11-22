#include <iostream>

int main()
{
  int size = 10;
  char array[size]{};

  char input = 0;
  int i = 0;
  std::cin >> std::noskipws;

  while ((std::cin >> input) && (i < size))
  {
    array[i++] = input;
  }

  std::cin >> std::skipws;

  for (int i = 0; i < size; ++i)
  {
    std::cout << array[i];
  }
  return 0;
}
