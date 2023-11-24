#include "taskOne.hpp"

size_t ara::countOfdifferentLetters(char *myArray, size_t arraySize)
{
  size_t arr[arraySize];
  size_t countOfDifferentLet = 0;
  int index = 0;
  for (size_t i = 0; myArray[i] != '\0'; i++)
  {
    if (std::isalpha(myArray[i]))
    {
      arr[i] = 1;
    }
  }

  for (size_t i = 0; myArray[i] != '\0'; i++)
  {
    ++countOfDifferentLet;
  }
  return countOfDifferentLet;
}
