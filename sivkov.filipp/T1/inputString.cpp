#include "inputShape.hpp"
#include "rectangle.hpp"
#include "concave.hpp"
#include "complexquad.hpp"
#include <string>


void inputRectangle(std::istream& input, Shape** shapes, size_t count)
{
  const size_t numberOfTops = 4;
  double tops[numberOfTops] = {};
  for (size_t i = 0; i < numberOfTops; ++i)
  {
    input >> tops[i];
  }
  if (!input)
  {
    throw std::runtime_error("Invalid tops");
  }
  shapes[count] = new Rectangle({ tops[0], tops[1] }, { tops[2], tops[3] });
}

void inputConcave(std::istream& input, Shape** shapes, size_t count)
{
  const size_t numberOfTops = 8;
  double tops[numberOfTops] = {};
  for (size_t i = 0; i < numberOfTops; ++i)
  {
    input >> tops[i];
  }
  if (!input)
  {
    throw std::runtime_error("Invalid tops");
  }
  shapes[count] = new Concave({ tops[0], tops[1] }, { tops[2], tops[3] }, { tops[4], tops[5] }, { tops[6], tops[7] });
}


void inputComplexQuad(std::istream& input, Shape** shapes, size_t count)
{
  const size_t numberOfTops = 8;
  double tops[numberOfTops] = {};
  for (size_t i = 0; i < numberOfTops; ++i)
  {
    input >> tops[i];
  }
  if (!input)
  {
    throw std::runtime_error("Invalid tops");
  }
  shapes[count] = new Complexquad({ tops[0], tops[1] }, { tops[2], tops[3] }, { tops[4], tops[5] }, { tops[6], tops[7] });
}

Shape** inputShape(std::istream& input, size_t& count)
{
  std::string shapeNames[3] = { "RECTANGLE","CONCAVE","COMPLEXQUAD" };
  std::string shape = "";
  Shape** arrayWithShape = nullptr;
  Shape** buffer = nullptr;
  char c = 0;
  while (input >> shape)
  {
    for (size_t i = 0; i < 3; ++i)
    {
      if (shape == shapeNames[i])
      {
        buffer = arrayWithShape;
        arrayWithShape = new Shape * [count + 1] {};
        if (buffer != nullptr)
        {
          for (size_t i = 0; i < count; ++i)
          {
            arrayWithShape[i] = buffer[i];
          }
        }
        delete[] buffer;
        try
        {
          if (shape == "RECTANGLE")
          {
            inputRectangle(input, arrayWithShape, count);
          }
          if (shape == "CONCAVE")
          {
            inputConcave(input, arrayWithShape, count);
          }
          if (shape == "COMPLEXQUAD")
          {
            inputComplexQuad(input, arrayWithShape, count);
          }
        }
        catch (const std::bad_alloc& e)
        {
          for (size_t i = 0; i < count; ++i)
          {
            delete arrayWithShape[i];
          }
          delete[] arrayWithShape;
          throw;
        }
        ++count;
      }
    }
    if (shape == "SCALE")
    {
      break;
    }
    input >> std::noskipws;
    while (c != '\n')
    {
      input >> c;
    }
    input >> std::skipws;
  }
  if (!input)
  {
    for (size_t i = 0; i < count; ++i)
    {
      delete arrayWithShape[i];
    }
    delete[] arrayWithShape;
    throw;
  }
  return arrayWithShape;
}
