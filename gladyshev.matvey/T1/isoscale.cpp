#include <iostream>

#include "isoscale.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "parallelogram.hpp"
#include "base-types.hpp"
#include "memoryallocate.hpp"

namespace gladyshev
{
  double * isoScale(const FigureData * arr, size_t countersup, double factor, double x, double y)
  {
    size_t length = 10;
    double * arrayAfterScale = new double[length];
    double afterScaleArea = 0;
    size_t con = 2;
    for (size_t i = 0; i < countersup; ++i)
    {
      if ((con + 4) >= length)
      {
        try
        {
          double * newArray = newMemory(arrayAfterScale, length);
          delete[] arrayAfterScale;
          arrayAfterScale = newArray;
          length += 10;
        }
        catch (const std::bad_alloc& e)
        {
          delete[] arrayAfterScale;
          throw;
        }
      }
      if (arr[i].name == "RECTANGLE")
      {
        Rectangle rectangle({ arr[i].cord[0], arr[i].cord[1] }, { arr[i].cord[2], arr[i].cord[3] });
        rectangle.scale({ x,y }, factor);
        arrayAfterScale[con] = rectangle.getFrameRect().pos.x - rectangle.getFrameRect().width / 2;
        ++con;
        arrayAfterScale[con] = rectangle.getFrameRect().pos.y - rectangle.getFrameRect().height / 2;
        ++con;
        arrayAfterScale[con] = rectangle.getFrameRect().pos.x + rectangle.getFrameRect().width / 2;
        ++con;
        arrayAfterScale[con] = rectangle.getFrameRect().pos.y + rectangle.getFrameRect().height / 2;
        ++con;
        afterScaleArea += rectangle.getArea();
      }
      else if (arr[i].name == "PARALLELOGRAM")
      {
        point_t p1 = { arr[i].cord[0],arr[i].cord[1] };
        point_t p2 = { arr[i].cord[2], arr[i].cord[3] };
        point_t p3 = { arr[i].cord[4], arr[i].cord[5] };
        Parallelogram parallelogram(p1, p2, p3);
        parallelogram.scale({ x,y }, factor);
        arrayAfterScale[con] = parallelogram.getFrameRect().pos.x - parallelogram.getFrameRect().width / 2;
        ++con;
        arrayAfterScale[con] = parallelogram.getFrameRect().pos.y - parallelogram.getFrameRect().height / 2;
        ++con;
        arrayAfterScale[con] = parallelogram.getFrameRect().pos.x + parallelogram.getFrameRect().width / 2;
        ++con;
        arrayAfterScale[con] = parallelogram.getFrameRect().pos.y + parallelogram.getFrameRect().height / 2;
        ++con;
        afterScaleArea += parallelogram.getArea();
      }
      else if (arr[i].name == "CIRCLE")
      {
        Circle circle({ arr[i].cord[0], arr[i].cord[1] }, arr[i].cord[2]);
        circle.scale({ x,y }, factor);
        arrayAfterScale[con] = circle.getFrameRect().pos.x - circle.getFrameRect().width / 2;
        ++con;
        arrayAfterScale[con] = circle.getFrameRect().pos.y - circle.getFrameRect().height / 2;
        ++con;
        arrayAfterScale[con] = circle.getFrameRect().pos.x + circle.getFrameRect().width / 2;
        ++con;
        arrayAfterScale[con] = circle.getFrameRect().pos.y + circle.getFrameRect().height / 2;
        ++con;
        afterScaleArea += circle.getArea();
      }
    }
    arrayAfterScale[0] = static_cast<double>(con);
    arrayAfterScale[1] = afterScaleArea;
    return arrayAfterScale;
  }
}
