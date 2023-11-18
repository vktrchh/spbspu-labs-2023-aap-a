#include <iostream>
#include <iomanip>

int main()
{
  char * buffer = new char[25]{};

  char symb = 0;
  size_t i = 0;

  while ((std::cin >> symb) && (i < 24))
  {
    buffer[i++] = symb;
  }

  std::cout << buffer << "\n";
}
