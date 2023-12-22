#include <iostream>
#include <sstream>

const int MAX_ARRAYS = 10;
const int MAX_ELEMENTS = 10;

int main()
{
  std::string arrayOfArrays[MAX_ARRAYS][MAX_ELEMENTS];
  int currentArray = 0;
  while (true)
  {
    std::string input;
    std::getline(std::cin, input);
    if (input == "0")
    {
      break;
    }
    std::istringstream stream(input);
    int currentElement = 0;
    std::string element;
    while (stream >> element && currentElement < MAX_ELEMENTS)
    {
      arrayOfArrays[currentArray][currentElement++] = element;
    }
    currentArray++;
    if (currentArray >= MAX_ARRAYS)
    {
      std::cerr << "Maximum number of arrays exceeded." << std::endl;
      return 1;
    }
  }
  for (int i = 0; i < currentArray; ++i)
  {
    for (int j = 0; j < MAX_ELEMENTS && !arrayOfArrays[i][j].empty(); ++j)
    {
      std::cout << arrayOfArrays[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
