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

bool * Alphabet(bool * alphabet, char * line, size_t length)
{
  for (size_t i = 0; i < length; ++i)
  {
    int symbol = line[i]-'a';
    if (symbol >= 0 && symbol <= 26)
    {
      alphabet[symbol] = true;
    }
  }
  return alphabet;
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
  char * new_alphabet = nullptr;
  try
  {
    alphabet = new bool [26]{};
    new_alphabet = new char [0]{};
  }
  catch (...)
  {
    std::cerr << "Dynamic memory overflow";
    delete [] new_line;
    return 1;
  }
  alphabet = Alphabet(alphabet, new_line, length);
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
        std::cerr << "Dynamic memory overflow";
        delete [] old_alphabet;
        return 1;
      }
      new_alphabet = CpLine(old_alphabet, new_alphabet, size);
      new_alphabet[n] = letter;
      ++size;
      ++n;
    }
  }
  delete [] new_line;
  delete [] alphabet;
  for (size_t i = 0; i < n; ++i)
  {
    std::cout << new_alphabet[i];
  }
  delete [] new_alphabet;
}
