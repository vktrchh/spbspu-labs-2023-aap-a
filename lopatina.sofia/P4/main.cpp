#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main(int argc, char ** argv)
{
  for (int i = 0; i < argc; ++i)
  {
    std::cout << argv[i] << '\n';
  }
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
    std::cout << "Num is " << num << '\n';
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value\n";
    return 1;
  }

  //argv[2] - имя файла с массивом
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
  std::cout << i << '\n';

  //argv[3] - имя файла для результата
  std::ofstream output(argv[3]);
  output << i << '\n';
}
