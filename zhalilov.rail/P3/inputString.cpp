#include "inputString.hpp"

char *zhalilov::resizeString(char string[], size_t &strSize)
{
  char *temp = nullptr;
  temp = new char[strSize * 2];
  for (size_t i = 0; i < strSize; i++)
  {
    temp[i] = string[i];
  }
  delete[] string;
  strSize *= 2;
  return temp;
}

char *zhalilov::inputString(std::istream &input)
{
  size_t strSize = 100;
  size_t dataIndex = 0;
  char *string = new char[strSize];

  input >> std::noskipws;
  char temp = 0;
  while (input >> temp)
  {
    if (temp == '\n')
    {
      string[dataIndex] = '\0';
      break;
    }
    else
    {
      string[dataIndex] = temp;
    }
    if (dataIndex + 1 == strSize)
    {
      try
      {
        string = resizeString(string, strSize);
      }
      catch (const std::bad_alloc &e)
      {
        delete[] string;
        throw e;
      }
    }
    dataIndex++;
  }
  input >> std::skipws;
  return string;
}
