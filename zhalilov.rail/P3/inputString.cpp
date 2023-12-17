#include "inputString.hpp"

char *zhalilov::increaseStrLen(char string[], const size_t size, const size_t dLength)
{
  char *temp = new char[size + dLength];
  for (size_t i = 0; i < size; i++)
  {
    temp[i] = string[i];
  }
  delete[] string;
  for (size_t i = size; i < size + dLength - 1; i++)
  {
    temp[i] = 0;
  }
  return temp;
}

std::istream &zhalilov::inputString(char string[], size_t size, size_t &endOfParse, std::istream &input)
{
  size_t dataIndex = 0;
  char temp = 0;
  input >> std::noskipws;
  while ((input >> temp) && (dataIndex < size))
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
    dataIndex++;
  }
  input >> std::skipws;
  endOfParse = dataIndex;
  return input;
}
