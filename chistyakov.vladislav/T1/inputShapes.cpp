#include "inputShapes.hpp"
#include <string>
#include "rectangle.hpp"
#include "square.hpp"
#include "complexquad.hpp"

void chistyakov::inputShapes(std::istream & input, Shape ** array, double * scaleInfo)
{
  std::string rectangle = "RECTANGLE";
  std::string square = "SQUARE";
  std::string complexquad = "COMPLEXQUAD";

  input >> std::noskipws;

  while (true)
  {
    std::string str = "";
    char now = 0;

    while (input >> now)
    {
      if (!input)
      {
        throw std::invalid_argument("Bad input, maybe try again?..");
      }

      if (str.size() == str.max_size() - 1)
      {
        throw std::logic_error("Seq too long");
      }

      if (now == '\n')
      {
        str += ' ';
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
      if (str[j] == ' ')
      {
        shapeName = str;
        shapeName.resize(j);
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
      parseInfoScale(str, scaleInfo);
      break;
    }
  }

  input >> std::skipws;
}

void chistyakov::inputRectangle(std::string str, Shape ** array)
{
  double cords[4]{};
  size_t index = 10;

  for (size_t tr = 0; tr < 4; ++tr)
  {
    if (index + 1 == str.size())
    {
      throw std::logic_error("Not enough coordinates for the shape (RECTANGLE)!");
    }

    for (size_t i = index; i < str.size(); ++i)
    {
      if (str[i] == ' ' || i + 1 == str.size())
      {
        cords[tr] = stod(str.substr(index, i - index));
        index = i + 1;
        break;
      }
    }
  }

  for (size_t i = index; i < str.size(); ++i)
  {
    if (str[i] != ' ')
    {
      throw std::invalid_argument("Too much cords for RECTANGLE!..");
    }
  }

  Rectangle * shape = new Rectangle({ {cords[0], cords[1]}, {cords[2], cords[3]} });
  writeShapeInArray(shape, array, 1000);
}

void chistyakov::inputSquare(std::string str, Shape ** array)
{
  double cords[3]{};
  size_t index = 7;

  for (size_t tr = 0; tr < 3; ++tr)
  {
    if (index + 1 == str.size())
    {
      throw std::logic_error("Not enough coordinates for the shape (SQUARE)!");
    }

    for (size_t i = index; i < str.size(); ++i)
    {
      if (str[i] == ' ')
      {
        cords[tr] = stod(str.substr(index, i - index));
        index = i + 1;
        break;
      }
    }
  }

  for (size_t i = index; i < str.size(); ++i)
  {
    if (str[i] != ' ')
    {
    }
  }

  Square * shape = new Square({ cords[0], cords[1] }, cords[2]);
  writeShapeInArray(shape, array, 1000);
}

void chistyakov::inputComplexquad(std::string str, Shape ** array)
{
  double cords[8]{};
  size_t index = 12;

  for (size_t tr = 0; tr < 8; ++tr)
  {
    if (index + 1 == str.size())
    {
      throw std::logic_error("Not enough coordinates for the shape (COMPLEXQUAD)!");
    }

    for (size_t i = index; i < str.size(); ++i)
    {
      if (str[i] == ' ')
      {
        cords[tr] = stod(str.substr(index, i - index));
        index = i + 1;
        break;
      }
    }
  }

  for (size_t i = index; i < str.size(); ++i)
  {
    if (str[i] != ' ')
    {
      throw std::invalid_argument("Too much cords for COMPLEXQUAD!..");
    }
  }

  point_t pnt1 = { cords[0], cords[1] };
  point_t pnt2 = { cords[2], cords[3] };
  point_t pnt3 = { cords[4], cords[5] };
  point_t pnt4 = { cords[6], cords[7] };

  Complexquad * shape = new Complexquad(pnt1, pnt2, pnt3, pnt4);
  writeShapeInArray(shape, array, 1000);
}

void chistyakov::writeShapeInArray(Shape * shape, Shape ** array, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    if (array[i] == nullptr)
    {
      array[i] = shape;
      break;
    }
  }
}

void chistyakov::freeArray(Shape ** array, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    if (array[i] == nullptr)
    {
      break;
    }
    delete array[i];
  }
}

void chistyakov::parseInfoScale(std::string str, double * scaleInfo)
{
  double cords[3]{};
  size_t index = 6;

  for (size_t tr = 0; tr < 8; ++tr)
  {
    if (index + 1 == str.size())
    {
      throw std::logic_error("Not enough arguments for isoScale!");
    }

    for (size_t i = index; i < str.size(); ++i)
    {
      if (str[i] == ' ')
      {
        cords[tr] = stod(str.substr(index, i - index));
        index = i + 1;
        break;
      }
    }
  }

  for (size_t i = index; i < str.size(); ++i)
  {
    if (str[i] != ' ')
    {
      throw std::invalid_argument("Too much cords for SCALE!..");
    }
  }

  scaleInfo[0] = cords[0];
  scaleInfo[1] = cords[1];
  scaleInfo[2] = cords[2];
}
