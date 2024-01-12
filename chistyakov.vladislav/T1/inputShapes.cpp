#include "inputShapes.hpp"
#include <string>

chistyakov::inputShapes(std::istream & input, Shape * array)
{
  std::string rectangle = "RECTANGLE";
  std::string square = "SQUARE";
  std::string complexquad = "COMPLEXQUAD";

  std::string str = "";
  char now = 0;

  input >> std::noskipws;

  while (true)
  {
    while (input >> now)
    {
      if (!input)
      {
        throw std::invalid_argument("Bad input, maybe try again?..");
      }

      if (str.size() == str.max_size() - 1)
      {
        throw logic_error("Seq too long");
      }

      if (now == "\n")
      {
        break;
      }
      else
      {
        str += now;
      }
    }

    std::string shapeName = "";
    for (size_t j = 0; j < str.size(); ++j)
    {
      if (str[j] == " ")
      {
        shapeName = str.resize(j);
        break;
      }
    }

    if (shapeName == rectangle)
    {
      inputRectangle(str, array);
    }
    else if (shapeName == square)
    {
      inputSquare(str, array);
    }
    else if (shapeName == complexquad)
    {
      inputComplexquad(str, array);
    }
    else if (shapeName == "SCALE")
    {
      break;
    }
  }
}

chistyakov::inputRectangle(str)
