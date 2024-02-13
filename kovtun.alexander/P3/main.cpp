#include <iostream>

int main()
{
  size_t size = 5;
  char c = '\n';
  char * input = new char[size]();

  for (size_t counter = 0; counter < size; counter++)
  {
    std::cin >> c;
    input[counter] = c;
  }

  for (int i = 0; i < size; i++)
  {
    std::cout << input[i];
  }
  delete [] input;

  return 0;
}
