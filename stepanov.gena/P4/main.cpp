#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

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
  // argv [1] - число, т.е. номер задания

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
    std::cerr << "Cannot parse a valute\n";
    return 3;
  }

  // argv [2] - имя файла с матрицей
  int i = 0;
  {
    std::ifstream input(argv[2]);
    input >> i;
    if (!input)
    {
      std::cerr << "Cannot read a number\n";
      return 2;
    }
  }

  std::cout << i << "\n";

  // argv [3] - имя файла для вывода результатов обработки
  std::ofstream output(argv[3]);
  output << i << "\n";

  //num == 1
  //int a[10000] = {};

  //num == 2
  //size_t rows = 0;
  //size_t cols = 0;
  // input >> rows >> cols;
  //int * a = new int[rows * cols]
  //a[i*cols + j
}
