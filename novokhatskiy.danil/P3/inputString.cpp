#include <iostream>
#include <stdexcept>
#include <cstddef>

int inArray(int arr[3][3], const size_t rows, const size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      std::cin >> arr[i][j];
      if (!std::cin)
      {
        std::cerr << "Incorrect input\n";
        return 1;
      }
    }
  }
  return 0;
}

void outArray(int arr[3][3], const size_t rows, const size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      std::cout << arr[i][j] << "\n";
    }
  }
}

int main()
{
  const size_t rows = 3;
  const size_t cols = 3;
  int arr[rows][cols];
  inArray(arr, 3, 3);
  outArray(arr, 3, 3);
}