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
}
