#include "inputShape.hpp"
#include "rectangle.hpp"
#include "concave.hpp"
#include "complexquad.hpp"
#include "othersFun.hpp"
#include <string>

void sivkov::inputRectangle(std::istream& input, Shape** shapes, size_t count)
{
  const size_t numberOfTops = 4;
  double tops[numberOfTops] = {};
  readTops(input, tops, numberOfTops);
  shapes[count] = new Rectangle({ tops[0], tops[1] }, { tops[2], tops[3] });
}

void sivkov::inputConcave(std::istream& input, Shape** shapes, size_t count)
{
  const size_t numberOfTops = 8;
  double tops[numberOfTops] = {};
  readTops(input, tops, numberOfTops);
  shapes[count] = new Concave({ tops[0], tops[1] }, { tops[2], tops[3] }, { tops[4], tops[5] }, { tops[6], tops[7] });
}


void sivkov::inputComplexQuad(std::istream& input, Shape** shapes, size_t count)
{
  const size_t numberOfTops = 8;
  double tops[numberOfTops] = {};
  readTops(input, tops, numberOfTops);
  shapes[count] = new Complexquad({ tops[0], tops[1] }, { tops[2], tops[3] }, { tops[4], tops[5] }, { tops[6], tops[7] });
}

sivkov::Shape** sivkov::inputShape(std::istream& input, size_t& count)
{
  std::string shapeNames[3] = { "RECTANGLE", "CONCAVE", "COMPLEXQUAD" };
  std::string shape = "";
  Shape** arrayWithShape = nullptr;
  Shape** buffer = nullptr;
  char c = 0;
  while (input >> shape && shape != "SCALE")
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
            sivkov::inputRectangle(input, arrayWithShape, count);
          }
          if (shape == "CONCAVE")
          {
            sivkov::inputConcave(input, arrayWithShape, count);
          }
          if (shape == "COMPLEXQUAD")
          {
            sivkov::inputComplexQuad(input, arrayWithShape, count);
          }
        }
        catch (const std::bad_alloc& e)
        {
          deleteMemory(arrayWithShape, count);
          throw;
        }
        catch (const std::logic_error& e)
        {
          std::cerr << e.what() << '\n';
          continue;
        }
        ++count;
      }
    }
  }
  input >> std::noskipws;
  while (c != '\n')
  {
    input >> c;
  }
  input >> std::skipws;
  if (!input)
  {
    deleteMemory(arrayWithShape, count);
    throw;
  }
  return arrayWithShape;
}

