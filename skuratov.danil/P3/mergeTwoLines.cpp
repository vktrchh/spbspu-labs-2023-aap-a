#include "mergeTwoLines.h"

#include <iostream>
#include <stdexcept>

char* skuratov::mergeTwoLines(char* result, const char* inputLine, const char* lineOfProgram)
{
  int i = 0;
  while (*inputLine != '\0')
  {
    result[i++] = *inputLine++;
  }
  while (*lineOfProgram != '\0')
  {
    result[i++] = *lineOfProgram++;
  }
  result[i] = '\0';
  return result;
}
