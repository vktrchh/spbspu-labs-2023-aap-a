#include <iostream>
#include <cctype>
#include <stdexcept>
#include "inputArray.hpp"
#include "taskOne.hpp"
#include "taskTwo.hpp"

int main()
{
  const size_t alphabetWeight = 26;

  size_t arrSize = 0;
  char * inputString = nullptr;

  char defoltStringForTaskTwo[8] = "def ghk";

  try
  {
    inputString = ara::inputArray(arrSize);
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    delete [] inputString;
    return 1;
  }

  size_t answerTaskOne = 0;
  answerTaskOne = arakelyanTaskOne::countOfdifferentLetters(inputString);
  char * answerTaskTwo = nullptr;

  try
  {
    answerTaskTwo = new char[alphabetWeight];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Cannot create a dynamic array for answerTaskTwo!";
    delete [] inputString;
    delete [] answerTaskTwo;
    return 1;
  }

  for (size_t i = 0; i < alphabetWeight; i++)
  {
    answerTaskTwo[i] = 0;
  }
  answerTaskTwo[alphabetWeight] = '\0';

  arakelyanTaskTwo::identicalLetters(inputString, defoltStringForTaskTwo, answerTaskTwo, alphabetWeight);

  if (answerTaskOne == 0)
  {
    std::cerr << "Empty input!\n";
    delete [] inputString;
    delete [] answerTaskTwo;
    return 1;
  }
  std::cout << answerTaskOne << "\n";

  delete [] answerTaskTwo;
  delete [] inputString;
  return 0;
}
