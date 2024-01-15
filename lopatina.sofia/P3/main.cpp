#include <iostream>
#include <iomanip>
//-----
#include <cstring>
//-----

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

void excludeCommon(char * first_str, const char * second_str, size_t size1, const size_t size2)
{
  for (size_t i = 0; i < size1; ++i)
  {
    if (first_str[i] == '\0')
    {
      break;
    }
    std::cout << "exc1: " << first_str[i] << '\n';
  }
  for (size_t j = 0; j < size2; ++j)
  {
    std::cout << "exc2: " << second_str[j] << '\n';
  }
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
      try
      {
        char * new_input = expandArray(input, amount);
        delete [] input;
        input = new_input;
        amount += 1;
      }
      catch (const std::bad_alloc & e)
      {
        std::cerr << e.what();
        return 1;
      }
    }
  }
  std::cin >> std::skipws;

  std::cout << input << '\n';
  std::cout << "size: " << strlen(input) << '\n';
  std::cout << "amount: " << amount << '\n';

  // вариант EXC-SND

  const char * string1 = "abc";
  const size_t size1 = 3;
  excludeCommon(input, string1, amount, size1);

 // вариант DGT-SND

  const char * string2 = "g1h2k";
  const size_t size2 = 5;
  //char * result2 = new char[amount]

   delete [] input;
}
