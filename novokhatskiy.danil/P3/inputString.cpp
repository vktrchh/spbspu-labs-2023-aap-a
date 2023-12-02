#include "inputString.hpp"

char* novokhatskiy::inputString(std::istream &input)
{
  size_t sizeString = 20;
  size_t cycleIndex = 0;
  char* string = nullptr;
  try
  {
    string = new char[sizeString];
  }
  catch (const std::bad_alloc& err)
  {
    throw err;
  }
  char symbol = 0;
  input >> std::noskipws;
  while ((input >> symbol) && (symbol != '\n')) 
  {
    string[cycleIndex] = symbol;
    if (cycleIndex >= sizeString)
    {
      try
      {
        char* newString = new char[sizeString + 15];
        for (size_t i = 0; i < sizeString; ++i)
        {
          newString[i] = string[i];
        }
        delete[] string;
        string = newString;
        sizeString += 15;
      }
      catch (...)
      {
        delete[] string;
      }
    }
    cycleIndex++;
  }
  input >> std::skipws;
  char* mainString = new char[sizeString];
  for (size_t i = 0; i < sizeString; ++i)
  {
    mainString[i] = string[i];
  }
  delete[] string;
  return mainString;
}
