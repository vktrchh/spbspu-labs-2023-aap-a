#include <iostream>
#include <cctype>

void deleteDigits(const char * string, const size_t & size, char * result)
{
  size_t j = 0;
  for (size_t i = 0; i < size; ++i)
  {
    if (!std::isdigit(string[i]))
    {
      result[j] = string[i];
      ++j;
    }
  }
}

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

char * inputString(std::istream & input, size_t & stringSize)
{
  const size_t bufferSize = 20;
  stringSize = bufferSize;
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
  char * string = nullptr;
  size_t size = 0;
  try
  {
    string = inputString(std::cin, size);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }

  char * result = new char[size];
  deleteDigits(string, size, result);
  std::cout << result << '\n';
  delete[] string;
  delete[] result;
}

