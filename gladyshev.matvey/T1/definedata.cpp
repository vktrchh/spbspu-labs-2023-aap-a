#include "definedata.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "parallelogram.hpp"

#include <iostream>

namespace gladyshev
{
  void inputPoints(std::istream& in, double * arrcords, size_t counter)
  {
    for (size_t i = 0; i < counter; ++i)
    {
      in >> arrcords[i];
      if (!in)
      {
        throw std::logic_error("bad input of data");
      }
    }
  }

  void inputScale(std::istream& in, point_t& pos, double& factor)
  {
    double dataScale[3]{};
    inputPoints(in, dataScale, 3);
    pos = { dataScale[0], dataScale[1] };
    factor = dataScale[2];
  }

  void freeMemory(Shape ** shapes, size_t amount)
  {
    for (size_t i = 0; i < amount; ++i)
    {
      delete shapes[i];
    }
  }

  Shape * identifyShape(const std::string& inputName, std::istream& in)
  {
    const char * names[] = { "RECTANGLE", "PARALLELOGRAM", "CIRCLE" };
    double p[6]{};
    for (size_t i = 0; i < 3; ++i)
    {
      if (inputName != names[i])
      {
        continue;
      }
      switch (i)
      {
        case 0:
          inputPoints(in, p, 4);
          return new Rectangle({ p[0], p[1] }, { p[2], p[3] });
        case 1:
          inputPoints(in, p, 6);
          return new Parallelogram({ p[0], p[1] }, { p[2], p[3] }, { p[4], p[5] });
        case 2:
          inputPoints(in, p, 3);
          return new Circle({ p[0], p[1] }, p[2]);
      }
    }
    throw std::invalid_argument("not a figure");
  }
  void isoScale(Shape * shapes, point_t pos, double factor)
  {
    rectangle_t frame = shapes->getFrameRect();
    double posfinishx = frame.pos.x;
    double posfinishy = frame.pos.y;
    shapes->move(pos);
    shapes->scale(factor);
    shapes->move(-(pos.x - posfinishx) * factor, -(pos.y - posfinishy) * factor);
  }
}
