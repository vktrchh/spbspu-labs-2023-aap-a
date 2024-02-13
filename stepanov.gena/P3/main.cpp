#include <iostream>
#include <iomanip>

int main()
{
  char buffer[20] = {};
  char symbol = 0;
  size_t i = 0;

  std::cin >> std::noskipws;
  while ((std::cin >> symbol) && (i < 19))
  {
    buffer[i++] = symbol;
    if (symbol == '\n')
    {
      buffer[i-1] = 0;
      break;
    }
  }
  std::cin >> std::skipws;

  std::cout << buffer << "\n";
}
