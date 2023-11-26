#include <iostream>
#include <cctype>

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
      return 1;
    }
    for (size_t j = 0; j < n; ++j)
    {
      input[j] = a[j];
    }
    delete [] a;
    std::cin >> c;
    if (!std::cin)
    {
      std::cerr << "Line not read";
      return 1;
    }
    input[i] = c;
    ++i;
    ++n;
  }
  std::cin >> std::skipws;
  for (size_t i = 0; i < n; ++i)
  {
    input[i] = tolower(input[i]);
  }
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
