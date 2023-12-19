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

  size_t inCodeArrSize = 8;
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

  size_t answerTaskOne = arakelyanTaskOne::countOfdifferentLetters(inputString);
  char * answerTaskTwo = nullptr;
  try
  {
    answerTaskTwo = new char[alphabetWeight];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Cannot create a dynamic array for answerTaskTwo!";
    delete [] inputString;
    return 1;
  }
  for (size_t i = 0; i < alphabetWeight; i++)
  {
    answerTaskTwo[i] = 0;
  }
  answerTaskTwo[alphabetWeight] = '\0';

  arakelyanTaskTwo::identicalLetters(inputString, defoltStringForTaskTwo, answerTaskTwo, alphabetWeight, arrSize);

  std::cout << "Answer on task 1: " << answerTaskOne << "\n";
  std::cout << "Answer on task 2: " << answerTaskTwo << "\n";

  delete [] answerTaskTwo;
  delete [] inputString;
  return 0;
}
