#include "inputOutputShapes.h"
#include <stdexcept>

#include "rectangle.h"
#include "square.h"
#include "diamond.h"
#include "parallelogram.h"

void skuratov::clearingShapes(Shape** shapes, size_t count)
{
  size_t i = 0;
  while (i < count)
  {
    delete shapes[i];
    ++i;
  }
  delete[] shapes;
}

void skuratov::inputRectangle(std::istream& input, Shape** shapes, size_t& count)
{
  double arguments[4] = {};
  size_t i = 0;
  while (i < 4)
  {
    input >> arguments[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid arguments for the Rectangle");
    }
    ++i;
  }
  shapes[count] = new Rectangle({ arguments[0], arguments[1] }, { arguments[2], arguments[3] });
  ++count;
}

void skuratov::inputSquare(std::istream& input, Shape** shapes, size_t& count)
{
  double arguments[3] = {};
  size_t i = 0;
  while (i < 3)
  {
    input >> arguments[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid arguments for the Square");
    }
    ++i;
  }
  shapes[count] = new Square({ arguments[0], arguments[1] }, arguments[2]);
  ++count;
}

void skuratov::inputDiamond(std::istream& input, Shape** shapes, size_t& count)
{
  double arguments[6] = {};
  size_t i = 0;
  while (i < 6)
  {
    input >> arguments[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid arguments for the Diamond");
    }
    ++i;
  }
  shapes[count] = new Diamond({ arguments[0], arguments[1] }, { arguments[2], arguments[3] }, { arguments[4], arguments[5] });
  ++count;
}

void skuratov::inputParallelogram(std::istream& input, Shape** shapes, size_t& count)
{
  double arguments[6] = {};
  size_t i = 0;
  while (i < 6)
  {
    input >> arguments[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid arguments for the Parallelogram");
    }
    ++i;
  }
  shapes[count] = new Parallelogram({ arguments[0], arguments[1] }, { arguments[2], arguments[3] }, { arguments[4], arguments[5] });
  ++count;
}
