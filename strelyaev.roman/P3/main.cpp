#include <iostream>
#include <iomanip>

void moveArray(char * old_array, size_t old_array_size, char * new_array)
{
  for (size_t i = 0; i < old_array_size; i++)
  {
    new_array[i] = old_array[i];
  }
  delete [] old_array;
}

char * inputArray(char * old_array, size_t old_array_size)
{
  char * new_array = new char [old_array_size + 50];
  moveArray(old_array, old_array_size, new_array);

  char c = 0;
  size_t i = 0;
  while ((c != '\n') && (i < old_array_size + 49))
  {
    std::cin >> c;
    new_array[i] = c;
    i++;
  }

  if (c == '\n')
  {
    return new_array;
  }

  return inputArray(new_array, old_array_size+50);
}

int main()
{
  std::cin >> std::noskipws;
  char * start_array = new char [1];
  char * end_array = inputArray(start_array, 1);
  std::cin >> std::skipws;

  std::cout << end_array;
}
