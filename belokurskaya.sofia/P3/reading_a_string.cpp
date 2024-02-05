#include "reading_a_string.hpp"

#include <cstring>
#include <algorithm>

char* belokurskaya::resizeStringBuffer(const char* my_string, const size_t size, const size_t new_memory)
{
  try
  {
    char* result = new char[new_memory + 1] {};

    std::copy(my_string, my_string + size, result);
    result[size] = '\0';

    return result;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    throw;
  }
}

std::string belokurskaya::inputString(std::istream& input)
{
  const size_t size_of_memory = 20;
  std::string input_str;
  char c;

  input >> std::noskipws;

  while ((input >> c) && c != '\n')
  {
    input_str += c;
    if (input_str.size() > size_of_memory)
    {
      input_str.resize(input_str.size() + size_of_memory);
    }
  }
  input >> std::skipws;

  if (input_str[0] == 0)
  {
    throw std::logic_error("Invalid input");
  }
  return input_str;
}
