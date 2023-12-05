#include "cpline.hpp"
#include "createalphabet.hpp"
#include <iostream>

int main()
{
  using namespace piyavkin;
  size_t length = 0;
  char c = 0;
  char * new_line = new char [0]{};
  char * old_line = nullptr;
  std::cin >> std::noskipws;
  while (c != '\n')
  {
    old_line = new_line;
    try
    {
      new_line = new char [length + 1]{};
    }
    catch (std::bad_alloc&)
    {
      std::cerr << "Dynamic memory overflow\n";
      delete [] old_line;
      return 1;
    }
    cpLine(old_line, new_line, length);
    std::cin >> c;
    if (!std::cin)
    {
      std::cerr << "Line not read\n";
      delete [] new_line;
      return 1;
    }
    new_line[length] = tolower(c);
    ++length;
  }
  std::cin >> std::skipws;
  bool alphabet [26] = {};
  char * new_alphabet = nullptr;
  char * old_alphabet = nullptr;
  createAlphabet(alphabet, new_line, length);
  delete [] new_line;
  size_t size = 0;
  for (int i = 0; i < 26; ++i)
  {
    if (alphabet[i] == false)
    {
      char letter = 'a' + i;
      old_alphabet = new_alphabet;
      try
      {
        new_alphabet = new char [size + 1]{};
      }
      catch (...)
      {
        std::cerr << "Dynamic memory overflow\n";
        delete [] old_alphabet;
        return 1;
      }
      cpLine(old_alphabet, new_alphabet, size);
      new_alphabet[size] = letter;
      ++size;
    }
  }
  for (size_t i = 0; i < size; ++i)
  {
    std::cout << new_alphabet[i];
  }
  std::cout << "\n";
  delete [] new_alphabet;
}
