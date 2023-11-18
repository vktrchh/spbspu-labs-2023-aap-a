#include <iostream>
#include <iomanip>

int main()
{
  char * buffer = new char[25]{};

  char symb = 0;
  size_t i = 0;

  std::cin >> std::noskipws;
  while ((std::cin >> symb) && (i < 24))
  {
    buffer[i++] = symb;
    if (symb == '\n')
    {
      buffer[i - 1] = 0;
      break;
    }
  }
  std::cin >> std::skipws;

  std::cout << buffer << "\n";
}
