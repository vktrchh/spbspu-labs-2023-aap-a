#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

size_t inputArray(std::istream & in, int * start, size_t amount, size_t toread)
{
  for (size_t i = 0; i < std::min(toread, amount); ++i)
  {
    if (!(in >> start[i]))
    {
      return i;
    }
  }
  return std::min(toread, amount);
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
    std::cerr << "First parameter is too large\n";
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
  //{
    std::ifstream input(argv[2]);
    input >> rows >> cols;;
    if (!input)
    {
      std::cerr << "Cannot read rows or cols\n";
      return 2;
    }
  //}
  std::cout << "Rows and cols are: " <<  rows << ' ' << cols << '\n';

  //------------------------
  // массив фиксированного размера; на стеке; кол-во элементов не превышает 10 000; num =  1
  if (num == 1)
  {
    int matrix[10000] = {};
    size_t result =  inputArray(input, matrix, rows * cols, rows * cols);
    std::cout << result << '\n';
  }
  // динамический массив ; free store; num = 2
  //------------------------


  //argv[3] - имя файла для результата
 // std::ofstream output(argv[3]);
 // output << i << '\n';
}
