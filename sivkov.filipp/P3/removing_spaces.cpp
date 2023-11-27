#include "removing_spaces.hpp"
#include <iostream>
void deleteSpace(char* string,size_t size,size_t k,char* arrayWithOutSpace)
{
  int isSpace = 0;
  int indexArr = 0;
  for (int j = 0; j < k; j++)
  {
      if (std::isspace(string[j]))
      {
          if (isSpace == 0)
          {
              arrayWithOutSpace[indexArr++] = ' ';
              isSpace = 1;
          }
      }
      else
      {
          arrayWithOutSpace[indexArr++] = string[j];
          isSpace = 0;
      }
  }
  if (indexArr > 0 && arrayWithOutSpace[0] == ' ')
  {
    for (int j = 0; j < indexArr - 1; j++)
    {
        arrayWithOutSpace[j] = arrayWithOutSpace[j + 1];
    }
    indexArr--;
  }
  arrayWithOutSpace[indexArr] = '\0';
}
