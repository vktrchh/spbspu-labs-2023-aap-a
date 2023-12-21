#include "taskTwo.hpp"
#include <iostream>
#include <cctype>

void arakelyanTaskTwo::identicalLetters(const char *inputArr, const char *defoltArray, char *answer, const size_t alphabetWeight)
{
  char alphabetArrayOne[26] = {1};
  char alphabetArrayTwo[26] = {1};

  for (size_t i = 0; inputArr[i] != '\0'; i++)
  {
    if (std::isalpha(inputArr[i]))
    {
      char symb = std::tolower(inputArr[i]);
      int index = symb - 'a';
      alphabetArrayOne[index] = symb;
    }
  }

  for (size_t i = 0; defoltArray[i] != '\0'; i++)
  {
    if (std::isalpha(defoltArray[i]))
    {
      char symb = std::tolower(defoltArray[i]);
      int index = symb - 'a';
      alphabetArrayTwo[index] = symb;
    }
  }

  for (size_t i = 0; i < alphabetWeight; i++)
  {
    if ((alphabetArrayOne[i] != 1) && (alphabetArrayTwo[i] == 1))
    {
      answer[i] = alphabetArrayOne[i];
    }
    else if ((alphabetArrayTwo[i] != 1) && (alphabetArrayOne[i] == 1))
    {
      answer[i] = alphabetArrayTwo[i];
    }
    else if (alphabetArrayOne[i] == alphabetArrayTwo[i])
    {
      answer[i] = alphabetArrayOne[i];
    }
    else
    {
      answer[i] = ' ';
    }
  }

}
