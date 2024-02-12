#include "removeSpaces.h"

void zakozhurnikova::removeSpaces(char *dest, const char *src, size_t buff)
{
  if (!src || !dest}
  {
    return;
  }
  size_t index = 0;
  for (size_t i = 1; i < buff; i++)
  {
    if (src[i] == '\0')
    {
      break;
  ++src;
  for (; *src != '\0'; ++src)
  {
    if (*(src - 1) != ' ')
    {
      *dest = *(src - 1);
      ++dest;
    }
    if (*src == ' ' && *(src - 1) != ' ')
    {
      *dest = *src;
      ++dest;
    }
  }

  if (*(dest - 1) == ' ')
  {
    *(dest - 1) = '\0';
  }
}
