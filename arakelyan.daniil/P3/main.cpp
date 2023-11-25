#include <iostream>
#include <cctype>
#include <stdexcept>
#include "inputArray.hpp"
#include "taskOne.hpp"

int main()
{
  size_t arrSize = 0;
  char * inputString = nullptr;
  const char * defoltStringForTaskTwo = "def_ghk";
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

  size_t answerTaskOne = ara::countOfdifferentLetters(inputString);
  if (answerTaskOne == 0)
  {
    std::cerr << "Error: No input\n";
    delete [] inputString;
    return 1;
  }
  else
  {
    std::cout << "Answer on task 1: " << answerTaskOne << "\n";
  }

  delete [] inputString;
  return 0;
}
