#include "taskTwo.hpp"
#include <iostream>
#include <cctype>

void arakelyanTaskTwo::findSymb(const char *array, char *answer)
{
  for (size_t i = 0; array[i] != '\0'; i++)
  {
    if (std::isalpha(array[i]))
    {
      char symb = std::tolower(array[i]);
      int index = symb - 'a';
      answer[index] = symb;
    }
  }
}

void arakelyanTaskTwo::identicalLetters(const char *inputArr, const char *defaultArray, char *answer, const size_t alphabetWeight)
{
  for (size_t i = 0; i < alphabetWeight; i++)
  {
    answer[i] = 1;
  }
  answer[alphabetWeight] = '\0';
  arakelyanTaskTwo::findSymb(inputArr, answer);
  arakelyanTaskTwo::findSymb(defaultArray, answer);
  // size_t lenght = 0;
  for (size_t i = 0; i < alphabetWeight; i++)
  {
    if (answer[i] == 1 && (i + 1 < alphabetWeight))
    {
      int temp = answer[i];
      answer[i] = answer[i+1];
      answer[i+1] = temp;
    }
    // lenght++;
  }
}
