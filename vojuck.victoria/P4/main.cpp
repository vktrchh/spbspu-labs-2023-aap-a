#include <iostream>
#include <fstream>
#include <cstdlib>


size_t inputArray(std::istream & in, int * array, size_t size, size_t toread);
int findMaxSum(int* array, int rows, int cols);
bool isUpperTriangular(int* matrix, int rows, int cols);
void fillMatrix(std::istream& in, int* array, size_t size);
void outputMatrix(int* array, size_t size);

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "there should be 3 args: a number of task, name of file to read and name of file to fill";
    return 1;
  }

  int num = 0;

  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 3;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value\n";
    return 3;
  }

  std::ifstream input(argv[2]);
  int rows = 0, cols = 0 ;
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read!\n";
    return 2;
  }

  if (rows != cols)
  {
    std::cerr << "The number of rows should be equal to cols\n";
    return 2;
  }

  if (num != 1 && num != 2)
  {
    std::cerr << "Invalid argument for a number of task\n";
    return 2;
  }

  int fixedMatrix[10000]{0};
  int* matrix = nullptr;

  std::ofstream output(argv[3]);

  if (num == 1)
  {
    matrix = fixedMatrix;
  }

  if (num == 2)
  {
    matrix = new int[rows * cols];
  }

  try
  {
    size_t result = inputArray(input, matrix, rows*cols, rows*cols);
    if (result == rows*cols)
    {
      int maxSum = findMaxSum(matrix, rows, cols);
      output << "Max sum: " << maxSum << "\n";
      output << "This matrix is" << (isUpperTriangular(matrix, rows, cols) ? "" : " not") << " upper triangular.\n";
    }
  }
  catch (std::bad_alloc &)
  {
    std::cerr << "Not enough memory\n";
    delete[] matrix;
    return 3;
  }
  catch (...)
  {
    std::cerr << "Something went wrong\n";
    delete[] matrix;
    return 1;
  }
  delete[] matrix;
}


void outputMatrix(int* array, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    std::cout << array[i] << " ";
  }
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
  int n = 5;
  int maxSum = 0;
  for (int i = 0; i < n; i++) {
        int sum1 = 0;
        int sum2 = 0;
    for (int j = 0; j < n - i; j++)
    {
      sum1 += array[j + rows*j + i];
      sum2 += array[j + i + cols*j];
    }
    maxSum = std::max(maxSum, std::max(sum1, sum2));
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


