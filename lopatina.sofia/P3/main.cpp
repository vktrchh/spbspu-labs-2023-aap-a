#include <iostream>
#include <iomanip>
#include <cctype>
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

char * excludeCommon(char * first_str, const char * second_str, size_t size1, const size_t size2)
{
  char * result = new char[size1];
  int flag = 0;
  size_t k = 0;
  for (size_t i = 0; i < size1; ++i)
  {
    if (first_str[i] == '\0')
    {
      result[k++] = first_str[i];
      break;
    }
    std::cout << "exc1: " << first_str[i] << '\n';
    for (size_t j = 0; j < size2; ++j)
    {
      if (first_str[i] == second_str[j])
      {
        flag = 1;
        std::cout << first_str[i] << " = " << second_str[j] << '\n';
      }
    }
    if (flag == 0)
    {
      result[k++] = first_str[i];
    }
    flag = 0;
  }
  return result;
}

char * addNumbers(char * first_str, const char * second_str, size_t size1, const size_t size2)
{
  char * result = new char[size1 + size2];
  size_t last = 0;
  for (size_t i = 0; i < size1; ++i)
  {
    if (first_str[i] == '\0')
    {
      last = i - 1;
      break;
    }
    result[i] = first_str[i];
  }
  for (size_t j = 0; j < size2; ++j)
  {
    if (isdigit(second_str[j]))
    {
      last += 1;
      result[last] = second_str[j];
    }
  }
  result[last + 1] = '\0';
  return result;
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
        delete [] input;
        return 1;
      }
    }
  }
  std::cin >> std::skipws;

  std::cout << input << '\n';
  std::cout << "size: " << strlen(input) << '\n';
  std::cout << "amount: " << amount << '\n';

  char * result1 = 0;
  char * result2 = 0;
  try
  {
    // вариант EXC-SND
    const char * string1 = "abc";
    const size_t size1 = 3;
    char * result1 = excludeCommon(input, string1, amount, size1);
    std::cout << "EXC-SND: " << result1 << '\n';
    delete [] result1;
  }
  catch(std::bad_alloc & e)
  {
    std::cerr << e.what();
    delete [] result1;
    delete [] input;
    return 1;
  }

  try
  {
    // вариант DGT-SND
    const char * string2 = "g1h2k";
    const size_t size2 = 5;
    char * result2 = addNumbers(input, string2, amount, size2);
    std::cout << "DGT-SND: " << result2 << '\n';
    delete [] result2;
  }
  catch(std::bad_alloc & e)
  {
    std::cerr << e.what();
    delete [] result2;
    delete [] input;
    return 1;
  }

  delete [] input;
}
