#include "removeSpaces.h"

void zakozhurnikova::removeSpaces(char *dest, const char *src, size_t buff)
{
  if (!src || !dest)
  {
    return;
  }
  size_t index = 0;
  for (size_t i = 1; i < buff; i++)
  {
    if (src[i] == '\0')
    {
      break;
    }
    if (src[i - 1] != ' ')
    {
      dest[index] = src[i - 1];
      index++;
    }
    if (src[i] == ' ' && src[i - 1] != ' ')
    {
      dest[index] = src[i];
      index++;
    }
  }
  if (dest[index - 1] == ' ')
  {
    dest[index - 1] = '\0';
  }
}
