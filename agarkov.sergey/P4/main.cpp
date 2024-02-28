#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Incorrect arg\n";
    return 1;
  }

  std::ifstream input_file(argv[2]);
  std::ofstream output_file(argv[3]);

  return 0;
}
