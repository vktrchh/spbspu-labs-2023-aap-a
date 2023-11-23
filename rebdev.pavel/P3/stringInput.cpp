#include "stringInput.hpp"
#include <stack>
#include <cstddef>

char * rebdev::inputStr(std::istream & input)
{
  input >> std::noskipws;

  char sym = 0;
  std::stack<char> newStack;

  while (sym != '\n')
  {
    input >> sym;

    if(!input)
    {
      input >> std::skipws;
      return nullptr;
    }

    newStack.push(sym);
  }

  char * firstStr = new char[newStack.size()];
  for(size_t i = (newStack.size() - 1); i >= 0; --i)
  {
    firstStr[i] = newStack.top();
    newStack.pop();
    if (i == 0)
    {
      break;
    }
  }

  return firstStr;
}
