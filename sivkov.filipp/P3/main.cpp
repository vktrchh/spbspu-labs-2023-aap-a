#include <iostream>

int main()
{
  char c = 0;
  size_t k = 0;
  int size = 20;
  char* string = new char[size];

  if (!string)
  {
    std::cerr << "Error with array" << "\n";
    return 1;
  }

  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    string[k++] = c;
    if (c == '\n')
    {
      break;
    }
  }
  std::cout << string << "\n";
  delete[] string;
  return 0;
}
