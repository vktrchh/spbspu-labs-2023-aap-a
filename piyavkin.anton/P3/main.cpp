#include "cpline.hpp"
#include "createalphabet.hpp"
#include <iostream>

int main()
{
  using namespace piyavkin;
  size_t length = 0;
  char c = 0;
  size_t i = 0;
  char * new_line = new char [0]{};
  std::cin >> std::noskipws;
  while (c != '\n')
  {
    char * old_line = new_line;
    try
    {
      new_line = new char [length + 1]{};
    }
    catch (...)
    {
      std::cerr << "Dynamic memory overflow\n";
      delete [] old_line;
      return 1;
    }
    new_line = cpLine(old_line, new_line, length);
    std::cin >> c;
    if (!std::cin)
    {
      std::cerr << "Line not read\n";
      delete [] new_line;
      return 1;
    }
    new_line[i] = c;
    new_line[i] = tolower(new_line[i]);
    ++i;
    ++length;
  }
  std::cin >> std::skipws;
  bool alphabet [26] = {};
  char * new_alphabet = nullptr;
  createAlphabet(alphabet, new_line, length);
  size_t size = 0;
  size_t n = 0;
  for (int i = 0; i < 26; ++i)
  {
    if (alphabet[i] == false)
    {
      char letter = 'a' + i;
      char * old_alphabet = new_alphabet;
      try
      {
        new_alphabet = new char [size + 1]{};
      }
      catch (...)
      {
        std::cerr << "Dynamic memory overflow\n";
        delete [] old_alphabet;
        delete [] new_line;
        return 1;
      }
      new_alphabet = cpLine(old_alphabet, new_alphabet, size);
      new_alphabet[n] = letter;
      ++size;
      ++n;
    }
  }
  delete [] new_line;
  for (size_t i = 0; i < n; ++i)
  {
    std::cout << new_alphabet[i];
  }
  delete [] new_alphabet;
}
