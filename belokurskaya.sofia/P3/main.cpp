int main()
{
  char * input = new char[20]{};
  char c = 0;
  size_t i = 0;
  std::cin >> std::noskipws;
  while ((std::cin >> c) && (i < 19))
  {
    input[i++] = c;
    if (c == '\n')
    {
      input[i - 1] = 0;
      break;
    }
  }
  std::cin >> std::skipws;
  std::cout << input << "\n";
  delete [] input;
}
