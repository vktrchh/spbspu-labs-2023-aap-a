#include <iostream>
#include <fstream>
#include <cstdlib>

void freeMatrix(int ** m, size_t rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    delete [] m[i];
  }
  delete [] m;
}

void freeMatrix(int ** m, size_t rows, size_t)
{
  freeMatrix(m, rows);
}

int ** createMatrix(size_t rows, size_t cols)
{
  int ** rowsptrs = new int *[rows];
  for (size_t i = 0; i < rows; ++i)
    {
      rowsptrs[i] = nullptr;
    }
  try
  {
    for (size_t i = 0; i < rows; ++i)
    {
      rowsptrs[i] = new int[cols];
    }
    return rowsptrs;
  }
  catch (const std::bad_alloc &)
  {
    freeMatrix(rowsptrs, rows, cols);
    throw "Error connected with free store\n";
  }
}

int main(int argc, char * argv[])
{
  for (int i = 0; i < argc; ++i)
  {
    std::cout << argv[i] << "\n";
  }
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }

  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first comand line argument is too large\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "First argument is not a number\n";
    return  1;
  }

  if (num > 2)
  {
    std::cerr << "Number of task is wrong\n";
    return 1;
  }

  size_t rows = 0, cols = 0;
  std::fstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read a number\n";
    return 2;
  }

  if (num == 1)
  {
    int matrix[10000];
    size_t count = 1;
    size_t maxRow = 0;
    size_t max = 0;
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        input >> matrix[i * rows + j];
      }
      if (matrix[i] == matrix[i + 1])
      {
        ++count;
        if (count > max)
        {
          max = count;
          maxRow = i + 1;
        }
      }
      else
      {
        count = 1;
      }
    }
    std::ofstream output(argv[3]);
    output << maxRow;

    input.close();
    return 0;
  }
  else if (num == 2)
  {
    int* matrix = new int[rows * cols];
    try
    {
       matrix = new int[rows * cols];
    }
    catch (const std::exception& e)
    {
      delete [] matrix;
      std::cerr << e.what();
      return 4;
    }
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        input >> matrix[i * rows + j];
      }
    }
    input.close();
    if (!input)
    {
      std::cerr << "Invalid value of matrix argyment\n";
      return 2;
    }
    size_t maxRow = 0;
    size_t count = 1;
    size_t max = 0;
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols - 1; ++j)
      {
        if (matrix[i * rows + j] == matrix[i * rows + j + 1])
        {
          ++count;
          if (count > max)
          {
            max = count;
            maxRow = i + 1;
          }
          else
          {
            max = 0;
          }
        }
        else
        {
          count = 1;
        }
        if (count > max)
        {
          max = count;
          maxRow = i + 1;
        }
        else
        {
          max = 0;
        }
      }
    }
    delete [] matrix;

    std::ofstream output(argv[3]);
    output << maxRow;
  }
}
