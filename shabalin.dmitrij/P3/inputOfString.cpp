#include "inputOfString.h"

char *shabalin::inputOfString(std::istream &input)
{
  size_t stringSize = 50;
  char *inputString = nullptr;
  try
  {
    char *inputString = new char[stringSize];
  }
  catch(const std::exception& e)
  {
    delete[] inputString;
    std::cerr << e.what() << '\n';
  }

  size_t count = 0;

  char process = 0;
  input >> std::noskipws;

  while (input >> process && process != '\n')
  {
    inputString[count] = process;
    count += 1;
    if (count == stringSize)
    {
      try
      {
        stringSize += 5;
        char *temporaryString = new char[stringSize];
        for (size_t i = 0; i < stringSize - 5; ++i)
        {
          temporaryString[i] = inputString[i];
        }
        delete[] inputString;
        inputString = temporaryString;
      }
      catch (const std::bad_alloc &e)
      {
        input >> std::skipws;
        delete[] inputString;
        throw;
      }
    }
  }
  inputString[count] = '\0';
  input >> std::skipws;
  return inputString;
}

