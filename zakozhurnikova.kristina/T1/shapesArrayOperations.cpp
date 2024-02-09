#include "shapesArrayOperations.hpp"
#include "inputOperations.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "diamond.hpp"
#include "complexquad.hpp"
#include <string>
#include <iostream>
#include <cstring>
#include <stdexcept>

zakozhurnikova::Shape* readRectangle(const char* string)
{
  const size_t RECT_WORD_LEN = 9;
  const size_t ARRAY_LEN = 4;
  double rectData[ARRAY_LEN]{};
  size_t pos = 0;
  string += RECT_WORD_LEN;
  for (size_t i = 0; i < ARRAY_LEN; ++i)
  {
    rectData[i] = std::stod(string, &pos);
    string += pos;
  }
  if (*string != '\0')
  {
    throw std::invalid_argument("Invalid rectangle parameters");
  }
  zakozhurnikova::point_t downLeft = { rectData[0], rectData[1] };
  zakozhurnikova::point_t upRight = { rectData[2], rectData[3] };
  return new zakozhurnikova::Rectangle(downLeft, upRight);
}

zakozhurnikova::Shape* readSquare(const char* string)
{
  const size_t SQUARE_WORD_LEN = 6;
  const size_t ARRAY_LEN = 3;
  double squareData[ARRAY_LEN]{};
  size_t pos = 0;
  string += SQUARE_WORD_LEN;
  for (size_t i = 0; i < ARRAY_LEN; ++i)
  {
    squareData[i] = std::stod(string, &pos);
    string += pos;
  }
  if (*string != '\0')
  {
    throw std::invalid_argument("Invalid square parameters");
  }
  zakozhurnikova::point_t downLeft = { squareData[0], squareData[1] };
  double length = squareData[2];

  return new zakozhurnikova::Square(downLeft, length);
}

zakozhurnikova::Shape* readDiamond(const char* string)
{
  const size_t SQUARE_WORD_LEN = 7;
  const size_t ARRAY_LEN = 6;
  double diamondData[ARRAY_LEN]{};
  size_t pos = 0;
  string += SQUARE_WORD_LEN;
  for (size_t i = 0; i < ARRAY_LEN; ++i)
  {
    diamondData[i] = std::stod(string, &pos);
    string += pos;
  }
  if (*string != '\0')
  {
    throw std::invalid_argument("Invalid diamond parameters");
  }

  zakozhurnikova::point_t pointOne = { diamondData[0], diamondData[1] };
  zakozhurnikova::point_t pointTwo = { diamondData[2], diamondData[3] };
  zakozhurnikova::point_t center = { diamondData[4], diamondData[5] };

  return new zakozhurnikova::Diamond(pointOne, pointTwo, center);
}

zakozhurnikova::Shape* readComplexquad(const char* string)
{
  const size_t COMPLEXQUAD_WORD_LEN = 11;
  const size_t ARRAY_LEN = 8;
  double complexquadData[ARRAY_LEN]{};
  size_t pos = 0;
  string += COMPLEXQUAD_WORD_LEN;
  for (size_t i = 0; i < ARRAY_LEN; ++i)
  {
    complexquadData[i] = std::stod(string, &pos);
    string += pos;
  }
  if (*string != '\0')
  {
    throw std::invalid_argument("Invalid diamond parameters");
  }

  zakozhurnikova::point_t pointOne = { complexquadData[0], complexquadData[1] };
  zakozhurnikova::point_t pointTwo = { complexquadData[2], complexquadData[3] };
  zakozhurnikova::point_t pointThree = { complexquadData[4], complexquadData[5] };
  zakozhurnikova::point_t pointFour = { complexquadData[6], complexquadData[7]};

  return new zakozhurnikova::Complexquad(pointOne, pointTwo, pointThree, pointFour);
}

zakozhurnikova::Shape* zakozhurnikova::readShape(const char* string)
{
  if (string && std::strncmp(string, "RECTANGLE", 9) == 0)
  {
    return readRectangle(string);
  }
  else if (string && std::strncmp(string, "SQUARE", 6) == 0)
  {
    return readSquare(string);
  }
  else if (string && std::strncmp(string, "DIAMOND", 7) == 0)
  {
    return readDiamond(string);
  }
  else if (string && std::strncmp(string, "COMPLEXQUAD", 11) == 0)
  {
    return readComplexquad(string);
  }
  else
  {
    throw std::invalid_argument("Invalid shape name");
  }
}

void zakozhurnikova::readScale(const char* string, zakozhurnikova::point_t& scalePoint, double& k)
{
  const size_t SCALE_PARAM_COUNT = 3;
  const size_t SCALE_WORD_LEN = 5;
  double scaleData[SCALE_PARAM_COUNT]{};
  size_t pos = 0;
  string += SCALE_WORD_LEN;
  for (size_t i = 0; i < SCALE_PARAM_COUNT; ++i)
  {
    scaleData[i] = std::stod(string, &pos);
    string += pos;
  }
  if (*string != '\0')
  {
    throw std::invalid_argument("Invalid scale parameters");
  }
  scalePoint = { scaleData[0], scaleData[1] };
  k = scaleData[2];
}

void zakozhurnikova::freeShapesArray(Shape** shapes, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shapes[i];
  }
}

void zakozhurnikova::inputShapesArray(std::istream& in, Shape** shapes, size_t& size, point_t& scalePoint, double& k)
{
  char* string = nullptr;
  while (true)
  {
    try
    {
      string = zakozhurnikova::readString(in);
      if (string && strncmp(string, "SCALE", 5) == 0)
      {
        readScale(string, scalePoint, k);
        delete[] string;
        return;
      }
      shapes[size] = zakozhurnikova::readShape(string);
      ++size;
      delete[] string;
    }
    catch (const std::invalid_argument& e)
    {
      delete[] string;
      throw std::invalid_argument(e.what());
    }
    catch (const std::logic_error& e)
    {
    }
    catch (const std::runtime_error& e)
    {
      delete[] string;
      throw std::runtime_error(e.what());
    }
  }
}
