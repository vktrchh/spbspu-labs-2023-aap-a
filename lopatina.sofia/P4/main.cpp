#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

size_t inputArray(std::istream & in, int * matrix, size_t amount, size_t toread)
{
  for (size_t i = 0; i < std::min(toread, amount); ++i)
  {
    if (!(in >> matrix[i]))
    {
      return i;
    }
  }
  return std::min(toread, amount);
}

int isLowerTriMatrix(int * matrix, size_t rows, size_t cols)
{
  if (rows != cols || rows == 0 || rows == 1)
  {
    return 0;
  }
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (i < j && matrix[i * rows + j] != 0)
      {
        return 0;
      }
    }
  }
  return 1;
}

size_t numDiagWithoutZero(int * matrix, size_t rows, size_t cols)
{
  if (rows != cols || rows == 0)
  {
    return 0;
  }
  size_t counter = 0;
  for (int i = 0; i < rows; ++i)
  {
    if (i == 0)
    {
      for (int j = 0; j < cols; ++j)
      {
        if (i != j)
        {
          counter += 1;
          int n1 = i, n2 = j;
          for (int k = 0; k < cols - j; ++k)
          {
            if (matrix[n1 * rows + n2] == 0)
            {
              counter -= 1;
              break;
            }
            n1 += 1;
            n2 += 1;
          }
        }
      }
    }
    else if (i > 0)
    {
      counter += 1;
      int n1 = i;
      for (int k = 0; k < rows - i; ++k)
      {
        if (matrix[n1 * rows + k] == 0)
        {
          counter -= 1;
          break;
        }
        n1 += 1;
      }
    }
  }
  return counter;
}


int main(int argc, char ** argv)
{
  //----for test----
  for (int i = 0; i < argc; ++i)
  {
    std::cout << argv[i] << '\n';
  }
  std::cout << '\n';
  //------------

  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }

  //argv[1] - номер задания (1 - массив фикс размера; 2 - динамический)
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
    std::cout << "Num is " << num << " but was " << argv[1] << '\n';
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  //argv[2] - имя файла с массивом
  size_t rows = 0, cols = 0;

  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read rows or cols\n";
    return 2;
  }
  std::cout << "Rows and cols are: " <<  rows << ' ' << cols << '\n';

  //------------------------
  // массив фиксированного размера; на стеке; кол-во элементов не превышает 10 000; num =  1
  if (num == 1)
  {
    int matrix[10000] = {};
    size_t result =  inputArray(input, matrix, rows * cols, rows * cols);
    //---for test---
    std::cout << "Result inputArray: " <<  result << '\n';
    std::cout << "Matrix: ";
    for (int i = 0; i < rows * cols; ++i)
    {
      std::cout << matrix[i] << ' ';
    }
    std::cout << '\n';
    //--------------
    if (result != rows * cols)
    {
      std::cerr << "Invalid input array\n";
      return 2;
    }
    //работа с матрицей (нижняя треугольная матрица => квадратная матрица)
    int res = isLowerTriMatrix(matrix, rows, cols);
    std::cout << "isLowerTriMatrix: " << res << '\n';
    //return 0;

  //------------------------------------
    size_t res2 = numDiagWithoutZero(matrix, rows, cols);
    std::cout << "numDiag: " << res2 << '\n';
    return 0;

  }

  // динамический массив ; free store; num = 2
  if (num == 2)
  {
    int * matrix = new int[rows * cols];
    size_t result =  inputArray(input, matrix, rows * cols, rows * cols);
    //---for test---
    std::cout << "Result inputArray: " <<  result << '\n';
    std::cout << "Matrix: ";
    for (int i = 0; i < rows * cols; ++i)
    {
      std::cout << matrix[i] << ' ';
    }
    std::cout << '\n';
    //--------------
    if (result != rows * cols)
    {
      std::cerr << "Invalid input array\n";
      delete[] matrix;
      return 2;
    }
  //работа с матрицей (нижняя треугольная матрица => квадратная матрица)
    int res = isLowerTriMatrix(matrix, rows, cols);
    std::cout << "isLowerTriMatrix: " << res << '\n';
    delete[] matrix;
    return 0;
  //------------------------------------
  }

  //------------------------


  //argv[3] - имя файла для результата
 // std::ofstream output(argv[3]);
 // output << i << '\n';
}
