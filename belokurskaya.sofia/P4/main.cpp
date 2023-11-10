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

void freeMatrix(int ** m, size_t rows, size_t cols)
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
  catch (const std::bab_alloc &)
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

  char * endOfParsing = nullptr;
  int num = std::strtoll(argv[1], &endOfParsing, 10);
  if (num == 0 && endOfParsing == argv[1])
  {
    std::cerr << "Cannot parse a value\n";
    return 2;
  }
  else if (num == 0 && endOfParsing != argv[1])
  {
    std::cout << "Num is zero\n";
  }
  else
  {
    std::cout << "Number is" << num << "\n";
  }

  size_t rows = 0, cols = 0;
  {
    std::fstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Cannot read a number\n";
      return 2;
    }
  }

  int ** rowptrs = nullptr;
  try
  {
    rowsptrs = createMatrix(rows, cols);
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "Not enough memory\n";
    return 3;
  }

  std::cout << rows << cols << "\n";

  std::ofstream output(argv[3]);
  output << rows << cols << "\n";
}
