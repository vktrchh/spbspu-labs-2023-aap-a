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

char *zhalilov::inputString(std::istream &input)
{
  size_t strSize = 100;
  size_t dataIndex = 0;
  char *string = nullptr;
  string = new char[strSize]{};
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
        string = increaseStrLen(string, strSize, 40);
        strSize += 40;
      }
      catch (const std::bad_alloc &e)
      {
        delete[] string;
        throw;
      }
    }
    dataIndex++;
  }
  input >> std::skipws;
  if (dataIndex == 0)
  {
    delete[] string;
    return nullptr;
  }
  return string;
}
