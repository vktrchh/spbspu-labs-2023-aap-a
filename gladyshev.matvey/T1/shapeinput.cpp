#include <iostream>

#include "memoryallocate.hpp"
#include "isoscale.hpp"
#include "shapeinput.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"
#include "circle.hpp"
#include "parallelogram.hpp"
#include "increasearray.hpp"

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
        double cords[6] = { 0 };
        for (size_t i = 0; i < 4; ++i)
        {
          in >> cords[i];
          if (!in)
          {
            delete[] arrayFigure;
            delete[] arrayBeforeScale;
            throw std::invalid_argument("bad input of rectangle coords");
          }
        }
        if ((cords[0] == cords[2]) || (cords[1] == cords[3]) || (cords[2] < cords[0]) || (cords[3] < cords[1]))
        {
          incorFig = true;
        }
        else
        {
          Rectangle rectangle({ cords[0], cords[1] }, { cords[2], cords[3] });
          arrayFigure[counterFigure].name = "RECTANGLE";
          for (size_t i = 0; i < 4; ++i)
          {
            arrayFigure[counterFigure].cord[i] = cords[i];
          }
          ++counterFigure;
          rectangle_t frame = rectangle.getFrameRect();
          increaseArray(arrayBeforeScale, counterFrame, frame);
          beforeScaleArea += rectangle.getArea();
        }
      }
      else if (inputName == "PARALLELOGRAM")
      {
        double cords[6] = { 0 };
        for (size_t i = 0; i < 6; ++i)
        {
          in >> cords[i];
          if (!in)
          {
            delete[] arrayFigure;
            delete[] arrayBeforeScale;
            throw std::invalid_argument("bad input of circle coords");
          }
        }
        if (!(((cords[1] == cords[3]) && (cords[3] != cords[5]) && (cords[0] != cords[2])) || ((cords[3] == cords[5]) && (cords[5] != cords[1]) && (cords[2] != cords[4]))))
        {
          incorFig = true;
        }
        else
        {
          Parallelogram parallelogram({ cords[0], cords[1] }, { cords[2], cords[3] }, { cords[4], cords[5] });
          arrayFigure[counterFigure].name = "PARALLELOGRAM";
          for (size_t i = 0; i < 6; ++i)
          {
            arrayFigure[counterFigure].cord[i] = cords[i];
          }
          ++counterFigure;
          rectangle_t frame = parallelogram.getFrameRect();
          increaseArray(arrayBeforeScale, counterFrame, frame);
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
          rectangle_t frame = circle.getFrameRect();
          increaseArray(arrayBeforeScale, counterFrame, frame);
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
