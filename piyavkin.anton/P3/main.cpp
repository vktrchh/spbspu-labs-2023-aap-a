#include "cpline.hpp"
#include "createalphabet.hpp"
#include <iostream>

int main()
{
  using namespace piyavkin;
  size_t length = 0;
  char sym = 0;
  char * new_line = nullptr;
  char * old_line = nullptr;
  std::cin >> std::noskipws;
  while (sym != '\n')
  {
    old_line = new_line;
    try
    {
      new_line = new char [length + 2]{};
    }
    catch (std::bad_alloc&)
    {
      std::cerr << "Dynamic memory overflow\n";
      delete [] old_line;
      return 1;
    }
    cpLine(old_line, new_line, length);
    std::cin >> sym;
    if (!std::cin)
    {
      std::cerr << "Line not read\n";
      delete [] new_line;
      return 1;
    }
    new_line[length] = tolower(sym);
    ++length;
  }
  std::cin >> std::skipws;
  new_line[length] = '\0';
  bool alphabet [26] = {};
  size_t count = createAlphabet(alphabet, new_line, length);
  delete [] new_line;
  char * new_alphabet = nullptr;
  try
  {
    new_alphabet = new char [count+1];
  }
  catch (...)
  {
    std::cerr << "Dynamic memory overflow\n";
    return 1;
  }
  new_alphabet[count] = '\0';
  char letter = 0;
  size_t size = 0;
  for (size_t i = 0; i < 26; ++i)
  {
    if (alphabet[i] == false)
    {
      letter = 'a' + i;
      new_alphabet[size] = letter;
      ++size;
    }
  }
  for (size_t i = 0; i < size; ++i)
  {
    std::cout << new_alphabet[i];
  }
  delete [] new_alphabet;
}
