#include <iostream>
#include <fstream>

int main(int argc, char ** argv)
{
  for (int i = 0; i < argc; ++i)
  {
    std::cout << argv[i] << '\n';
  }
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  //argv[1] - номер задания (1 - массив фикс размера; 2 - динамический)

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
