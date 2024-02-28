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
  if (!input_file.is_open())
  {
    std::cerr << "Error input file\n";
    return 1;
  }
  if (!output_file.is_open())
  {
    std::cerr << "Error output file\n";
    return 1;
  }
  return 0;
  
}
