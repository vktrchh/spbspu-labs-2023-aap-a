#include <iostream>
#include <cctype>
#include <stdexcept>
#include "inputArray.hpp"
#include "taskOne.hpp"
#include "taskTwo.hpp"

int main()
{
  const size_t alphabetWeight = 26;

  char * inputString = nullptr;
  const char * defaultStringForTaskTwo = "def ghk";

  try
  {
    inputString = arakelyan::inputArray(std::cin);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Memory cannot be allocated!\n";
    return 1;
  }

  using namespace arakelyanTaskOne;
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

  using namespace arakelyanTaskTwo;
  identicalLetters(inputString, defaultStringForTaskTwo, answerTaskTwo, alphabetWeight);

  std::cout << answerTaskOne << "\n" << answerTaskTwo << "\n";


  delete [] answerTaskTwo;
  delete [] inputString;
  return 0;
}
