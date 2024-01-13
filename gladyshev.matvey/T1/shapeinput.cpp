#include <iostream>

#include "memoryallocate.hpp"
#include "isoscale.hpp"
#include "shapeinput.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"
#include "circle.hpp"
#include "parallelogram.hpp"

namespace gladyshev
{
  std::pair<double *, double *> makeString(std::istream& in, bool& incorFig, bool& unsupFig)
  {
    std::string inputName = "";
    size_t counterFigure = 0;
    size_t counterFrame = 2;
    size_t lenFigure = 10;
    size_t lenFrame = 10;
    double beforeScaleArea = 0;
    FigureData * arrayFigure = new FigureData[lenFigure];
    double * arrayBeforeScale = nullptr;
    try
    {
      arrayBeforeScale = new double[lenFrame];
    }
    catch (const std::bad_alloc& e)
    {
      delete[] arrayFigure;
      throw;
    }
    while (in >> inputName)
    {
      if ((counterFrame + 4) >= lenFrame)
      {
        try
        {
          double * newArray = newMemory(arrayBeforeScale, lenFrame);
          delete[] arrayBeforeScale;
          arrayBeforeScale = newArray;
          lenFrame += 10;
        }
        catch (const std::bad_alloc& e)
        {
          delete[] arrayBeforeScale;
          delete[] arrayFigure;
          throw;
        }
      }
      if ((counterFigure + 1) == lenFigure)
      {
        try
        {
          FigureData * newArray = newMemoryStruct(arrayFigure, lenFigure);
          delete[] arrayFigure;
          arrayFigure = newArray;
          lenFigure += 10;
        }
        catch (const std::bad_alloc& e)
        {
          delete[] arrayFigure;
          delete[] arrayBeforeScale;
          throw;
        }
      }
      if (inputName == "RECTANGLE")
      {
        double p1x, p1y, p2x, p2y = 0;
        in >> p1x >> p1y >> p2x >> p2y;
        if (!in)
        {
          delete[] arrayFigure;
          delete[] arrayBeforeScale;
          throw std::invalid_argument("bad input of rectangle coords");
        }
        if ((p1x == p2x) || (p1y == p2y) || (p2x < p1x) || (p2y < p1y))
        {
          incorFig = true;
        }
        else
        {
          Rectangle rectangle({ p1x, p1y }, { p2x, p2y });
          arrayFigure[counterFigure].name = "RECTANGLE";
          arrayFigure[counterFigure].cord[0] = p1x;
          arrayFigure[counterFigure].cord[1] = p1y;
          arrayFigure[counterFigure].cord[2] = p2x;
          arrayFigure[counterFigure].cord[3] = p2y;
          ++counterFigure;
          arrayBeforeScale[counterFrame] = p1x;
          ++counterFrame;
          arrayBeforeScale[counterFrame] = p1y;
          ++counterFrame;
          arrayBeforeScale[counterFrame] = p2x;
          ++counterFrame;
          arrayBeforeScale[counterFrame] = p2y;
          ++counterFrame;
          beforeScaleArea += rectangle.getArea();
        }
      }
      else if (inputName == "PARALLELOGRAM")
      {
        double p1x, p1y, p2x, p2y, p3x, p3y = 0;
        in >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;
        if (!in)
        {
          delete[] arrayFigure;
          delete[] arrayBeforeScale;
          throw std::invalid_argument("bad input of circle coords");
        }
        if (!(((p1y == p2y) && (p2y != p3y) && (p1x != p2x)) || ((p2y == p3y) && (p3y != p1y) && (p2x != p3x))))
        {
          incorFig = true;
        }
        else
        {
          Parallelogram parallelogram({ p1x, p1y }, { p2x, p2y }, { p3x, p3y });
          arrayFigure[counterFigure].name = "PARALLELOGRAM";
          arrayFigure[counterFigure].cord[0] = p1x;
          arrayFigure[counterFigure].cord[1] = p1y;
          arrayFigure[counterFigure].cord[2] = p2x;
          arrayFigure[counterFigure].cord[3] = p2y;
          arrayFigure[counterFigure].cord[4] = p3x;
          arrayFigure[counterFigure].cord[5] = p3y;
          ++counterFigure;
          arrayBeforeScale[counterFrame] = parallelogram.getFrameRect().pos.x - parallelogram.getFrameRect().width / 2;
          ++counterFrame;
          arrayBeforeScale[counterFrame] = parallelogram.getFrameRect().pos.y - parallelogram.getFrameRect().height / 2;
          ++counterFrame;
          arrayBeforeScale[counterFrame] = parallelogram.getFrameRect().pos.x + parallelogram.getFrameRect().width / 2;
          ++counterFrame;
          arrayBeforeScale[counterFrame] = parallelogram.getFrameRect().pos.y + parallelogram.getFrameRect().height / 2;
          ++counterFrame;
          beforeScaleArea += parallelogram.getArea();
        }
      }
      else if (inputName == "CIRCLE")
      {
        double p1x, p1y, radius = 0;
        in >> p1x >> p1y >> radius;
        if (!in)
        {
          delete[] arrayFigure;
          delete[] arrayBeforeScale;
          throw std::invalid_argument("bad input of circle coords");
        }
        if (radius <= 0)
        {
          incorFig = true;
        }
        else
        {
          Circle circle({ p1x, p1y }, radius);
          arrayFigure[counterFigure].name = "CIRCLE";
          arrayFigure[counterFigure].cord[0] = p1x;
          arrayFigure[counterFigure].cord[1] = p1y;
          arrayFigure[counterFigure].cord[2] = radius;
          ++counterFigure;
          arrayBeforeScale[counterFrame] = circle.getFrameRect().pos.x - circle.getFrameRect().width / 2;
          ++counterFrame;
          arrayBeforeScale[counterFrame] = circle.getFrameRect().pos.y - circle.getFrameRect().height / 2;
          ++counterFrame;
          arrayBeforeScale[counterFrame] = circle.getFrameRect().pos.x + circle.getFrameRect().width / 2;
          ++counterFrame;
          arrayBeforeScale[counterFrame] = circle.getFrameRect().pos.y + circle.getFrameRect().height / 2;
          ++counterFrame;
          beforeScaleArea += circle.getArea();
        }
      }
      else if (inputName == "SCALE")
      {
        if (counterFrame == 2)
        {
          delete[] arrayFigure;
          delete[] arrayBeforeScale;
          throw std::logic_error("lack of supported data");
        }
        arrayBeforeScale[0] = static_cast<double>(counterFrame);
        arrayBeforeScale[1] = beforeScaleArea;
        double x, y, factor = 0;
        in >> x >> y >> factor;
        if (!in)
        {
          delete[] arrayFigure;
          delete[] arrayBeforeScale;
          throw std::invalid_argument("bad input of scale");
        }
        double * arrlast = nullptr;
        try
        {
          arrlast = isoScale(arrayFigure, counterFigure, factor, x, y);
        }
        catch (const std::logic_error& e)
        {
          delete[] arrayFigure;
          delete[] arrayBeforeScale;
          throw;
        }
        delete[] arrayFigure;
        return std::make_pair(arrayBeforeScale, arrlast);
      }
      else
      {
        unsupFig = true;
      }
    }
    if (in.eof())
    {
      delete[] arrayFigure;
      delete[] arrayBeforeScale;
      throw std::runtime_error("EOF");
    }
    return std::make_pair(nullptr, nullptr);
   }
}
