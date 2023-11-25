#include "taskOne.hpp"

size_t arakelyanTaskOne::countOfdifferentLetters(char *myArray)
{
  size_t countOfDifferentLet = 0;
  char alphabet[26] = {0};
  for (size_t i = 0; myArray[i] != '\0'; i++)
  {
    char symb = std::tolower(myArray[i]);
    if (std::isalpha(symb))
    {
      int ourSimb = symb - 'a';
      alphabet[ourSimb] = 1;
    }
  }

  for (size_t i = 0; i < 26; i++)
  {
    if (alphabet[i] > 0)
    {
      ++countOfDifferentLet;
    }
  }
  if (countOfDifferentLet == 0)
  {
    return 0;
  }
  else
  {
    return countOfDifferentLet;
  }
}
