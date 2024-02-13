#include "mergeTwoLines.h"
#include "transformInputString.h"

#include <iostream>
#include <stdexcept>

char* skuratov::mergeTwoLines(const char* inputLine, const char* lineOfProgram, size_t size)
{
  int i = 0;
  char* result = new char[size];
  while (*inputLine != '\0' || *lineOfProgram != '\0')
  {
    if (*inputLine != '\0')
    {
      result[i] = *inputLine;
      i++;
      inputLine++;
    }
    if (*lineOfProgram != '\0')
    {
      result[i] = *lineOfProgram;
      i++;
      lineOfProgram++;
    }
  }
  result[i] = '\0';
  return result;
}
