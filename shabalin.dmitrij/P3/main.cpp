#include "duplicateNumbers.h"
#include "makeLowerCaseString.h"
#include "inputOfString.h"

/*
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

  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    for (size_t j = 1; str[j] != '\0' ; ++j)
    {
      if ((str[i] == str[j]) && (isdigit(str[i])))
      {
        return 1;
      }
    }
  }
  return 0;
}

char *makeLowerCaseString(char *str, char *result)
{
  if (str == nullptr || *str == '\0')
  {
    return 0;
  }
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    if(isupper(str[i]))
      {
        str[i] = tolower(str[i]);
      }
  }
  for (size_t j = 0; str[j] != '\0'; ++j)
  {
    result[j] = str[j];
  }
  return result;
}
*/

int main()
{
  using namespace shabalin;
  char *finalyString = nullptr;

  try
  {
    finalyString = shabalin::inputOfString(std::cin);
  }
  catch (std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    delete[] finalyString;
    return 1;
  }

  if (finalyString[0] == '\0')
  {
    delete[] finalyString;
    std::cerr << "Error";
    return 1;
  }

  //char *answer2 = new char[stringSize + 1];
  //char *answer2 = nullptr;

  /*
  try
  {
    char *answer2 = new char[stringSize + 1];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Error" << "\n";
    delete[] answer2;
    return 1;
  }
  */

//char *answer2 = new char[stringSize];
  size_t answer = shabalin::duplicateNumbers(finalyString);
  std::cout << answer << "\n";

  /*
  try
  {
    char *answer2 = makeLowerCaseString(finalyString, );
    std::cout << answer2;
  }
  catch (std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    delete[] finalyString;
    return 1;
  }
  */

  char result[] = "123";
  shabalin::makeLowerCaseString(finalyString, result);
  std::cout << result;

  return 0;
}
