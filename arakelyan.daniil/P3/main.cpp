#include <_ctype.h>
#include <ios>
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

  size_t inCodeArrSize = 9;
  const char *defoltStringForTaskTwo = "def ghk";

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

  size_t answerTaskOne = arakelyanTaskOne::countOfdifferentLetters(inputString);
  char * answerTaskTwo = nullptr;
  try
  {
    answerTaskTwo = new char[alphabetWeight];
  }
  catch (...)
  {

  }
  for (size_t i = 0; i < alphabetWeight; i++)
  {
    answerTaskTwo[i] = 0;
  }
  answerTaskTwo[alphabetWeight] = '\0';

  arakelyanTaskTwo::identicalLetters(inputString, defoltStringForTaskTwo, answerTaskTwo, alphabetWeight, arrSize);
  
  // if (!answerTaskTwo)
  // {
  //   std::cerr << "Cannot create array for second task\n";
  //   delete [] inputString;
  //   return 1;
  // }

  std::cout << "Answer on task 1: " << answerTaskOne << "\n";
  std::cout << "Answer on task 2: " << answerTaskTwo << "\n";

  // delete [] answerTaskTwo;
  delete [] inputString;
  return 0;
}
