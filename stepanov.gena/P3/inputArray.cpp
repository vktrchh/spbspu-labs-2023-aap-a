#include "inputArray.hpp"
#include <istream>

char* stepanov::inputArray(std::istream& input)
{
  char* string = nullptr;
  size_t sizeString = 20;
  char symbol = 0;
  size_t index = 0;
  string = new char[sizeString];
  while (input >> symbol && symbol != '\n')
  {
    string[index] = symbol;
    index += 1;
  }
  return 0;
}
