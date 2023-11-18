#include <iostream>
#include <iomanip>

int main()
{
  const size_t bufferSize = 25;
  size_t arraySize = 0;

  char symb = 0;
  size_t i = 0;
  bool status = true;

  char* actualArray = new char[arraySize + bufferSize]{};

  std::cin >> std::noskipws;
  do
  {
    char* buffer = new char[bufferSize]{};
    while ((i != bufferSize) && (std::cin >> symb))
    {
      buffer[i++] = symb;
      if (symb == '\n')
      {
        buffer[i - 1] = '\0';
        status = false;
        break;
      }
    }

    size_t position = arraySize;
    for (size_t j = 0; j != bufferSize; ++j)
    {
      actualArray[position] = buffer[j];
      ++position;
    }
    arraySize += bufferSize;

    char* tempArray = new char[arraySize]{};
    for (size_t j = 0; j != arraySize; ++j)
    {
      tempArray[j] = actualArray[j];
    }
    delete [] actualArray;

    actualArray = new char[arraySize + bufferSize]{};
    for (size_t j = 0; j != arraySize; ++j)
    {
      actualArray[j] = tempArray[j];
    }
    delete [] tempArray;

    i = 0;

    if (!status)
    {
      std::cout << actualArray << '\n';
      delete [] actualArray;
      actualArray = nullptr;
    }
  }
  while (status);
  std::cin >> std::skipws;

  return 0;
}
