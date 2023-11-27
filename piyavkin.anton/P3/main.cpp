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
  size_t n = 0;
  char c = 0;
  size_t i = 0;
  char * input = new char [0]{};
  std::cin >> std::noskipws;
  while (c != '\n')
  {
    char * a = input;
    try
    {
      input = new char [n+1]{};
    }
    catch (...)
    {
      std::cerr << "Dynamic memory overflow";
      delete [] a;
      return 1;
    }
    input = CpLine(a, input, n);
    std::cin >> c;
    if (!std::cin)
    {
      std::cerr << "Line not read";
      return 1;
    }
    input[i] = c;
    input[i] = tolower(input[i]);
    ++i;
    ++n;
  }
  std::cin >> std::skipws;
  bool * alphabet = new bool [26]{};
  for (size_t i = 0; i < n; ++i)
  {
    int k = input[i]-'a';
    if (k >= 0 && k <= 26)
    {
      alphabet[k] = true;
    }
  }
  for (int i = 0; i < 26; ++i)
  {
    if (alphabet[i] == false)
    {
      char l = 'a' + i;
      std::cout << l;
    }
  }
}
