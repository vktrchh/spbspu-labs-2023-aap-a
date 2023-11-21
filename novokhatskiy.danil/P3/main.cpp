#include <cctype>
#include <string>
#include <iostream>

void result(const char* in, char* out)
{
  do
  {
    if(!std::isalpha(*in))
    {
      *out++ = *in;
    }
  }
  while(*++in);
}

int main()
{
  std::string s;
  std::getline(std::cin, s);
  char * output = new char[s.size()];
  result(s.c_str(),output);
  std::cout << output << "\n";
  delete[] output;
}

