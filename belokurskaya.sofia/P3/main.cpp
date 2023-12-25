#include <iostream>
#include <cstring>
#include <cctype>
#include <stdexcept>

void transformString(void transformString(const char * input, char * result, char * not_input_chars)
{
  const int the_size_of_the_latin_alphabet = 26;
  int is_letter_present[the_size_of_the_latin_alphabet] = {0};

  for (size_t i = 0; i < std::strlen(input); ++i)
  {
    char c = std::tolower(input[i]);
    if (std::isalpha(c))
    {
      if (c - 'a' >= 0 && c - 'a' < the_size_of_the_latin_alphabet)
      {
        is_letter_present[c - 'a'] = 1;
      }
    }
  }

  size_t j = 0;
  for (int i = 0; i < the_size_of_the_latin_alphabet; ++i)
  {
    if (!is_letter_present[i])
    {
      if (j < the_size_of_the_latin_alphabet)
      {
        not_input_chars[j++] = static_cast< char >('a' + i);
      }
    }
  }

  if (j < the_size_of_the_latin_alphabet)
  {
    not_input_chars[j] = '\0';
  }
}

void toLowerCase(char * input)
{
  for (size_t i = 0; i < std::strlen(input); ++i)
  {
    if (std::isalpha(input[i]) && std::isupper(input[i]))
    {
      input[i] = std::tolower(input[i]);
    }
  }
}

char * resizeStringBuffer(const char * my_string, const size_t size, const size_t new_memory)
{
  char * result = new char[new_memory] {};

  std::copy(my_string, my_string + size, result);

  return result;
}

char * inputString(std::istream& input)
{
  const size_t size_of_memory = 0;
  size_t string_size = 0;
  char * string = new char[size_of_memory] {};
  char c;
  size_t i = 0;

  input >> std::noskipws;

  while ((input >> c) && c != '\n')
  {
    if (i > string_size)
    {
      try
      {
        string = resizeStringBuffer(string, string_size, string_size + size_of_memory);
      }
      catch (const std::bad_alloc& e)
      {
        delete[] string;
        throw e;
      }
      string_size += size_of_memory;
    }
    string[i++] = c;
  }

  input >> std::skipws;
  return string;
}

int main()
{
  try
  {
    char * input_str = inputString(std::cin);
    char * not_input_chars = new char[26]{};

    transformString(input_str, nullptr, not_input_chars);

    std::cout << not_input_chars << '\n';

    char* original_input_str = resizeStringBuffer(input_str, std::strlen(input_str), std::strlen(input_str) + 1);

    toLowerCase(original_input_str);

    std::cout << original_input_str << '\n';

    delete[] not_input_chars;
    delete[] original_input_str;
    delete[] input_str;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  return 0;
}
