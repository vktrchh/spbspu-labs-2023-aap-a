#include "reallocate.hpp"

char* grechishnikov::inputStr(std::istream& in, size_t& size)
{
  size = 10;
  char * curStr = nullptr;
  try
  {
    curStr = new char[size];
  }
  catch (const std::bad_alloc &e)
  {
    throw std::logic_error("Cannot allocate memory");
  }

  char chInput = '0';
  size_t curPos = 0;
  in >> std::noskipws;
  while (chInput != '\n' && in >> chInput)
  {
    curStr[curPos] = chInput;
    curPos++;
    if (curPos % size == 0 && curStr[curPos] != '\n')
    {
      try
      {
        curStr = reallocate(curStr, size, size + 10);
      }
      catch (const std::bad_alloc &e)
      {
        throw std::logic_error("Cannot allocate mamory");
      }
      size += 10;
    }
  }
  if (curPos == 1)
  {
    throw std::logic_error("String is empty");
  }
  in >> std::skipws;
  return curStr;
}

char* grechishnikov::reallocate(char* str, size_t lenF, size_t lenS)
{
  char* newStr = new char [lenS];
  for (size_t i = 0; i < lenS; ++i)
  {
    newStr[i] = 0;
  }
  size_t min = (lenF < lenS) ? lenF : lenS;
  for (size_t i = 0; i < min; ++i)
  {
    newStr[i] = str[i];
  }
  delete[] str;
  return newStr;
}
