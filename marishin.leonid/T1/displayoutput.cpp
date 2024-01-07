#include "displayoutput.hpp"

namespace marishin
{
  void outputShapesInfo(std::ostream& out, size_t shapeCount, Shape** shapes)
  {
    double totalArea = 0;

    for (size_t i = 0; i < shapeCount; ++i)
    {
      totalArea += shapes[i]->getArea();
    }

    out << "Total Area: " << totalArea << " ";


  }
}
