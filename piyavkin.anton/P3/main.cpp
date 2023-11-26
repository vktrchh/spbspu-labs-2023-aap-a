#include <iostream>

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
    input = new char [n+1];
    for (size_t j = 0; j < n; ++j)
    {
      input[j] = a[j];
    }
    delete [] a;
    std::cin >> c;
    input[i] = c;
    ++i;
    ++n;
  }
  for (size_t i = 0; i < n; ++i)
  {
    std::cout << input[i];
  }
}
