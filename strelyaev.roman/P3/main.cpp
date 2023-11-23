#include <iostream>
#include <iomanip>
#include <cctype>

void moveArray(char * old_array, size_t old_array_size, char * new_array)
{
  for (size_t i = 0; i < old_array_size; i++)
  {
    new_array[i] = old_array[i];
  }
  delete [] old_array;
}

char * inputArray(char * old_array, size_t old_array_size, size_t * current_array_size)
{
  char * new_array = new char [old_array_size + 10];
  *current_array_size += 10;
  moveArray(old_array, old_array_size, new_array);

  char c = 0;
  size_t i = old_array_size - 1;
  while ((c != '\n') && (i < old_array_size + 9))
  {
    std::cin >> c;
    new_array[i] = c;
    i++;
  }

  if (c == '\n')
  {
    return new_array;
  }
  return inputArray(new_array, old_array_size + 10, current_array_size);
}

int checkDigit(const char * symbol_array, char * digit_array, size_t symbol_array_size)
{
  int position = 0;
  for (size_t i = 0; i < symbol_array_size; i++)
  {
    if (isdigit(symbol_array[i]))
    {
      for (int q = 0; q < 10; q++)
      {
        if (symbol_array[i] == digit_array[q])
        {
          return 1;
        }
      }
        digit_array[position++] = symbol_array[i];
    }
  }
  return 0;
}

int main()
{
  std::cin >> std::noskipws;
  size_t current_array_size = 0;
  char * end_array = nullptr;
  char * start_array = nullptr;

  try
  {
  start_array = new char [1];
  end_array = inputArray(start_array, 1, &current_array_size);
  }
  catch (...)
  {
    delete [] start_array;
    delete [] end_array;
    return 1;
  }
  std::cin >> std::skipws;
  char * digit_array = new char [10];
  if (!(checkDigit(end_array, digit_array, current_array_size)))
  {
    delete [] end_array;
    delete [] digit_array;
    std::cout << "Не нашлось(\n";
    return 0;
  }
  else
  {
    delete [] end_array;
    delete [] digit_array;
    std::cout << "Нашлось!\n";
    return 3;
  }
}
