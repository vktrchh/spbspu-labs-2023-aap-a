#include <iostream>

char * expandString(const char * string, const size_t size, const size_t newSize)
{
  char * result = new char[newSize];
  for (size_t i = 0; i < size; ++i)
  {
    result[i] = string[i];
  }
  delete[] string;
  return result;
}

char * inputString(std::istream & input)
{
  const size_t bufferSize = 20;
  size_t stringSize = 20;
  char * string = new char[bufferSize]{0};
  char c;
  size_t i = 0;
  input >> std::noskipws;
  while ((input >> c))
  {
    if (i >= stringSize)
    {
      try
      {
        string = expandString(string, stringSize, stringSize + bufferSize);
      }
      catch (const std::bad_alloc & e)
      {
        delete[] string;
        throw e;
      }
      stringSize += bufferSize;
    }
    string[i++] = c;
    if (c == '\n')
    {
      string[i - 1] = 0;
      break;
    }
  }
  input >> std::skipws;
  return string;
}

int main()
{
  try
  {
    char * string = inputString(std::cin);
    std::cout << string << '\n';
    delete[] string;
  }
  catch(const std::bad_alloc & e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
}

