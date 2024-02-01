#include "mergeTwoLines.h"

#include <iostream>
#include <stdexcept>

#include "transformInputString.h"

char* skuratov::mergeTwoLines(char* result, char* inputLine, const char* lineOfProgram)
{
  int i = 0;

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
