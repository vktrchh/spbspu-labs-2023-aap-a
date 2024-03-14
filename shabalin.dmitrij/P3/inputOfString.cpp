/*
#include "inputOfString.h"
#include <stdexcept>

char *shabalin::inputOfString(std::istream &input)
{
  size_t stringSize = 10;
  size_t count = 0;
  char *initialString = new char[stringSize];
  char currentChar = 0;

  input >> std::noskipws;
  try
  {
    while ((input >> currentChar) && (currentChar != '\n'))
    {
      initialString[count] = currentChar;
      count += 1;
      if (count == stringSize)
      {
        stringSize += 10;
        char *newArray = new char[stringSize];
        for (size_t i = 0; i < stringSize - 10; ++i)
        {
          newArray[i] = initialString[i];
        }
        delete[] initialString;
        initialString = newArray;
      }
    }
    initialString[count] = '\0';
    input >> std::skipws;
  }
  catch (const std::bad_alloc &e)
  {
    input >> std::skipws;
    delete[] initialString;
    throw;
  }
  return initialString;
}

#include "inputOfString.h"
#include <stdexcept>
#include <iostream>
#include <cstddef>

char *shabalin::inputOfString(std::istream &input, char *initialString)
{
  size_t initialSize = 0;
  size_t count = 0;
  char currentChar = 0;
  char *newArray = nullptr;

  input >> std::noskipws;

  try
  {
    initialString = new char[initialSize]();
    while ((input >> currentChar) && (currentChar != '\n'))
    {
      initialString[count] = currentChar;
      count += 1;
      if (count == initialSize)
      {
        initialSize *= 2;
        newArray = new char[initialSize]();
        for (size_t i = 0; i < initialSize; ++i)
        {
          newArray[i] = initialString[i];
        }
        delete[] initialString;
        initialString = newArray;
        delete[] newArray;
      }
    }
    initialString[count] = '\0';
    input >> std::skipws;
    return initialString;
  }
  catch (const std::bad_alloc &e)
  {
    throw;
  }
}

#include "inputOfString.h"
#include <cstring>
#include <iostream>

char *shabalin::inputOfString(std::istream &input, char *initialString, size_t &initialSize)
{
  initialString = new char[initialSize];
  char inputChar = 0;

  size_t count = 0;

  input >> std::noskipws;

  while (input >> inputChar)
  {
    if (!input)
    {
      throw std::runtime_error("Error input");
    }
    if (count == initialSize - 1)
    {
      initialSize += 10;
      char *tempString = new char[initialSize];

      for (size_t i = 0; i < count; i++)
      {
        tempString[i] = initialString[i];
      }

      delete[] initialString;
      initialString = tempString;
    }
    else
    {
      initialString[count] = inputChar;
      count++;

      if (inputChar == '\n')
      {
        initialString[count - 1] = '\0';
        break;
      }
    }
  }
  return initialString;
}
*/

#include "inputOfString.h"

char* shabalin::inputOfString(std::istream & input)
{
  size_t sizeOfString = 50;
  char *inputArray = new char[sizeOfString];

  char char_ = 0;
  size_t i = 0;
  input >> std::noskipws;

  while ((input >> char_))
  {
    if (i == sizeOfString)
    {
      try
      {
        char* newArray = new char[sizeOfString + 10];
        for (size_t i = 0; i < sizeOfString; ++i)
        {
          newArray[i] = inputArray[i];
        }
        delete[] inputArray;
        inputArray = newArray;
        sizeOfString += 10;
      }
      catch (const std::bad_alloc &)
      {
        delete[] inputArray;
        input >> std::skipws;
        throw;
      }
    }
    if (char_ == '\n')
    {
      inputArray[i] = 0;
      break;
    }
    if (!input)
    {
      delete[] inputArray;
      input >> std::skipws;
      throw std::invalid_argument("Bad input, maybe try again?..");
    }
    inputArray[i++] = char_;
  }
  input >> std::skipws;
  return inputArray;
}
