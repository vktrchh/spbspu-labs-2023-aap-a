#include "inputArray.hpp"
#include <iomanip>

char* stepanov::inputArray(std::istream& input, size_t& sizeString)
{
  char* string = nullptr;
  char symbol = 0;
  size_t index = 0;
  try
  {
    string = new char[sizeString] {};
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Not enough memory: " << e.what() << '\n';
    return nullptr;
  }
  input >> std::noskipws;
  while (input >> symbol)
  {
    if (symbol == '\n')
    {
      break;
    }
    else if (index == sizeString - 1)
    {
      sizeString += 20;
      try
      {
        char* newString = new char[sizeString] {};
        for (size_t i = 0; i < index; i++)
        {
          newString[i] = string[i];
        }
        delete[] string;
        string = newString;
      }
      catch (const std::bad_alloc& e)
      {
        std::cerr << "Not enough memory: " << e.what() << '\n';
        delete[] string;
        input >> std::skipws;
        return nullptr;
      }
    }
    string[index++] = symbol;
  }
  input >> std::skipws;

  return string;
}

