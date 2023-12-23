#include <iostream>
#include <cstddef>
#include <cstring>
#include "stringInput.hpp"
#include "stringConvert.hpp"


int main()
{
  char * firstStr = nullptr;

  try
  {
    firstStr = rebdev::acceptStr(std::cin);
  }
  catch (const std::exception & e)
  {
    delete[] firstStr;
    std::cerr << e.what();
    return 1;
  }
  if (firstStr == nullptr)
  {
    std::cerr << "String is empty";
    return 1;
  }

  char const * const secondStr = "1 2ok 3 5z 3pv21";

  size_t numOfDig = 0;
  for (size_t i = 0; i < strlen(secondStr); ++i)
  {
    if (std::isdigit(secondStr[i]))
    {
      numOfDig += 1;
    }
  }

  char * rez = nullptr;
  try
  {
    rez = new char[strlen(firstStr) + numOfDig];
    for (size_t i = 0; i < (strlen(firstStr) + numOfDig); ++i)
    {
      rez[i] = '0';
    }
  }
  catch (const std::exception & e)
  {
    return 2;
  }

  rebdev::convertString(firstStr, secondStr, rez);

  std::cout << rez << '\n';
  delete[] rez;
  delete[] firstStr;

  return 0;
}
