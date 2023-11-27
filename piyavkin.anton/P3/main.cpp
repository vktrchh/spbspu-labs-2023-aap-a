#include <iostream>
#include <cctype>

char * CpLine(char * old_line, char * new_line, size_t length)
{
  for (size_t i = 0; i < length; ++i)
  {
    new_line[i] = old_line[i];
  }
  delete [] old_line;
  return new_line;
}

int main()
{
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
      std::cerr << "Dynamic memory overflow";
      delete [] old_line;
      return 1;
    }
    new_line = CpLine(old_line, new_line, length);
    std::cin >> c;
    if (!std::cin)
    {
      std::cerr << "Line not read";
      return 1;
    }
    new_line[i] = c;
    new_line[i] = tolower(new_line[i]);
    ++i;
    ++length;
  }
  std::cin >> std::skipws;
  bool * alphabet = nullptr;
  try
  {
    alphabet = new bool [26]{};
  }
  catch (...)
  {
    std::cerr << "Dynamic memory overflow";
    delete [] new_line;
    return 1;
  }
  for (size_t i = 0; i < length; ++i)
  {
    int symbol = new_line[i]-'a';
    if (symbol >= 0 && symbol <= 26)
    {
      alphabet[symbol] = true;
    }
  }
  for (int i = 0; i < 26; ++i)
  {
    if (alphabet[i] == false)
    {
      char letter = 'a' + i;
      std::cout << letter;
    }
  }
  delete [] new_line;
  delete [] alphabet;
}
