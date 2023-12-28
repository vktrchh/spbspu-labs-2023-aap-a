#include "taskTwo.hpp"
#include <iostream>
#include <cctype>

void arakelyanTaskTwo::findSymb(const char *array, char *answer, size_t &pos)
{
  size_t flag = 0;
  for (size_t i = 0; array[i] != '\0'; ++i)
  {
    if (std::isalpha(array[i]))
    {
      char symb = std::tolower(array[i]);
      for (size_t j = 0; answer[j] != '\0'; ++j)
      {
        if (answer[j] == symb)
        {
          flag++;
        }
      }
      if (flag == 0)
      {
        answer[pos++] = symb;
      }
      flag = 0;
    }
  }
}

void arakelyanTaskTwo::identicalLetters(const char *inputArr, const char *defaultArray, char *answer, const size_t alphabetWeight)
{
  size_t a = 0;
  size_t & index = a;
  arakelyanTaskTwo::findSymb(inputArr, answer, index);
  arakelyanTaskTwo::findSymb(defaultArray, answer, index);
  for (size_t i = 0; i < alphabetWeight - 1; ++i)
  {
    for (size_t j = 0; j < alphabetWeight - i - 1; ++j)
    {
      if (std::isalpha(answer[j]) && std::isalpha(answer[j+1]))
      {
        if (answer[j] > answer[j+1])
        {
          int temp = answer[j];
          answer[j] = answer[j+1];
          answer[j+1] = temp;
        }
      }
    }
  }
  answer[a+1] = '\0';
}
