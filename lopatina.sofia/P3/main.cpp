#include <iostream>
#include <iomanip>

char * expandArray(char * arr, size_t size)
{
  size_t new_size = size + 1;
  char * new_arr = new char[new_size];
  for (size_t i = 0; i < (size - 1); ++i)
  {
    new_arr[i] = arr[i];
  }
  return new_arr;
}

int main()
{
  char * input = new char[20]{};
  char c = 0;
  size_t i = 0;
  size_t amount = 20;

  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    input[i++] = c;
    if (c == '\n')
    {
      input[i - 1] = 0;
      break;
    }
    if (i == (amount - 1))
    {
      char * new_input = expandArray(input, amount);
      delete [] input;
      input = new_input;
      amount += 1;
    }
  }
  std::cin >> std::skipws;

  std::cout << input << '\n';
  delete [] input;
}
