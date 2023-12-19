int main(int argc, char * argv[])
{

  if (argc != 4)
  {
    std::cerr << "Invalid amount of arguments";
    return 1;
  }

  int arrType = 0;
  try
  {
    arrType = std::stoi(argv[1]);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << "Invalid first argument";
    return 1;
  }

  if (arrType != 1 && arrType != 2)
  {
    std::cerr << "First argument can only be '1' or '2'";
    return 1;
  }

  std::ifstream iFile(argv[2]);
  if (!iFile.is_open())
  {
    std::cerr << "Couldn't open input file";
    return 2;
  }

  size_t rows = 0;
  size_t cols = 0;

  iFile >> rows >> cols;
}
