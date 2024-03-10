#include <iostream>
#include <ifstream>
#include <ofstream>
#include <cstdlib>


size_t inputArray(std::istream & in, int * array, size_t size, size_t toread);
int findMaxSum(int* array, int rows, int cols);
bool isUpperTriangular(int* matrix, int rows, int cols);

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "it's will be a number of task, name of file to read and name of file to fill";
    return 1;
  }
  int i  = 0;
  {
    std::ifstream input(argv[2]);
    input >> i;
    if(!input)
    {
      std::cerr << "cannot read";
      return 2;
    }
  }
  std::ofstream output(argv[3]);
  output << i << "\n";

}



size_t inputArray(std::istream & in, int * array, size_t size, size_t toread)
{
  for (size_t i = 0; i < std::min(size, toread); ++i)
  {
    in >> array[i];
    if (!in)
    {
      return i;
    }
  }
  return std::min(size, toread);
}


int findMaxSum(int* array, int rows, int cols)
{
  int maxSum = 0;
  for (int i = 0; i < rows; i++)
  {
    int sum = 0;
    for (int j = i; j < rows * cols; j += (cols + 1))
    {
      if (j % cols <= i)
      {
        sum += array[j];
      }
    }
      if (sum > maxSum)
      {
        maxSum = sum;
      }
  }
  for (int i = cols; i < rows * cols; i += cols)
  {
    int sum = 0;
    for (int j = i; j < rows * cols; j += (cols - 1))
    {
      if (j % cols >= i % cols)
      {
        sum += array[j];
      }
    }
      if (sum > maxSum)
      {
        maxSum = sum;
      }
  }
  return maxSum;
}

bool isUpperTriangular(int* matrix, int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (i > j && matrix[i * cols + j] != 0)
      {
        return false;
      }
    }
  }
  return true;
}
