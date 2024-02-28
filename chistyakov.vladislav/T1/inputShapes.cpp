#include "inputShapes.hpp"
#include <string>
#include "rectangle.hpp"
#include "square.hpp"
#include "complexquad.hpp"

void chistyakov::inputShapes(std::istream & input, Shape ** array, double * scaleInfo, size_t & size)
{
  std::string rectangle = "RECTANGLE";
  std::string square = "SQUARE";
  std::string complexquad = "COMPLEXQUAD";
  std::string shapeName = "";
  std::string str = "";
  char now = 0;

  input >> std::noskipws;

  while (std::getline(input, shapeName, " "))
  {
    if (shapeName.find(rectangle))
    {
      inputRectangle(input, array, size);
    }
    else if (shapeName.find(square))
    {
      inputSquare(input, array, size);
    }
    else if (shapeName.find(complexquad))
    {
      inputComplexquad(input, array, size);
    }
    else if (shapeName.find("SCALE"))
    {
      parseInfoScale(str, scaleInfo);
      break;
    }
  }

  input >> std::skipws;
}

void chistyakov::inputRectangle(std::istream & input, Shape ** array, size_t & size)
{
  double cords[4]{};
  inputDouble(input, 4, cords);

  try
  {
    Rectangle * shape = new Rectangle({ {cords[0], cords[1]}, {cords[2], cords[3]} });
    writeShapeInArray(shape, array, 1000);
    size++;
  }
  catch(const std::invalid_argument & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
  }
}

void chistyakov::inputSquare(std::istream & input, Shape ** array, size_t & size)
{
  double cords[3]{};
  inputDouble(input, 3, cords);

  try
  {
    Square * shape = new Square({ cords[0], cords[1] }, cords[2]);
    writeShapeInArray(shape, array, 1000);
    size++;
  }
  catch(const std::invalid_argument & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
  }
}

void chistyakov::inputComplexquad(std::istream & input, Shape ** array, size_t & size)
{
  double cords[8]{};
  inputDouble(input, 8, cords);

  point_t pnt1 = { cords[0], cords[1] };
  point_t pnt2 = { cords[2], cords[3] };
  point_t pnt3 = { cords[4], cords[5] };
  point_t pnt4 = { cords[6], cords[7] };

  try
  {
    Complexquad * shape = new Complexquad(pnt1, pnt2, pnt3, pnt4);
    writeShapeInArray(shape, array, 1000);
    size++;
  }
  catch(const std::invalid_argument & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
  }
}

void chistyakov::inputDouble(std::istream & input, size_t numOfPoints, double * pointsArray)
{
  double num = 0;

  for (size_t i = 0; i < numOfPoints; ++i)
  {
    if (!input >> num)
    {
      throw std::logic_error("Bad input!\n");
    }

    pointsArray[i] = num;
  }
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
  inputDouble(input, 8, cords);

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
