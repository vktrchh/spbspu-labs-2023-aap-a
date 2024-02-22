#include <cstring>
#include <exception>
#include <ios>
#include <iostream>
#include <cstddef>

char *inputOfString(std::istream &input)
{
  size_t stringSize = 50;
  char *inputString = nullptr;
  
  size_t stringSize_ = stringSize;

  try 
  {
    inputString = new char[stringSize]();

    char process;
    size_t i = 0;

    input >> std::noskipws;
    
    while (input >> process && process != '\n')
    {
      inputString[i] = process;
      ++i;

      if (i >= stringSize)
      {
        stringSize_ += stringSize;
        char *temporaryString = new char[stringSize_]();
        std::copy(inputString, inputString + i, temporaryString);
        delete[] inputString;
        inputString = temporaryString;
      }
    }
    //inputString[stringSize] = '\0';
    //return inputString;
    if (i == 0 || inputString[0] == '\n')
    {
      delete[] inputString;
      throw;
    }
  }
  catch (const std::bad_alloc &e)
  {
    input >> std::skipws;
    delete[] inputString;
    throw;
  }
  inputString[stringSize] = '\0';
  return inputString;
}

int duplicateNumbers(const char *str)
{
  if (str == nullptr || *str == '\0')
  {
    return 0;
  }

  for (size_t i = 0; i < str[i] != '\0'; ++i)
  {
    for (size_t j = 0; j < str[j] != '\0' ; ++j)
    {
      if ((str[i] == str[j]) && (isdigit(str[i])) && (i != j))
      {
        return 1;
      }
    }
  }
  return 0;
}

int main()
{
  char *finalyString = nullptr;

  try 
  {
    finalyString = inputOfString(std::cin);
  }
  catch (std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  if (finalyString[0] == '\0')
  {
    delete[] finalyString;
    std::cerr << "Error.";
    return 1;
  }
  size_t answer = duplicateNumbers(finalyString);
  std::cout << answer << "\n";
  return 0;
}
