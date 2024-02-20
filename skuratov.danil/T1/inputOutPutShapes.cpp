#include "inputOutputShapes.h"
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
  double args[4] = {};
  size_t i = 0;
  while (i < 4)
  {
    input >> args[i];
    if (!input)
    {
      throw std::invalid_argument("Invalid arguments for the Rectangle in input");
    }
    ++i;
  }
  shapes[count] = new Rectangle({ args[0], args[1] }, { args[2], args[3] });
  ++count;
}
