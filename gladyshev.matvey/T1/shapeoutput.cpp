#include <iomanip>

#include "shapeoutput.hpp"

namespace gladyshev
{
  std::ostream& outData(std::ostream& out, const double * firstArr, const double * secArr, bool incorFig, bool unsupFig)
  {
    size_t firstCounter = 1;
    size_t secondCounter = 1;
    while (firstCounter < firstArr[0] - 1)
    {
      out << std::fixed << std::setprecision(1) << firstArr[firstCounter] << " ";
      ++firstCounter;
    }
    out << std::fixed << std::setprecision(1) << firstArr[firstCounter];
    out << "\n";
    while (secondCounter < secArr[0] - 1)
    {
      out << std::fixed << std::setprecision(1) << secArr[secondCounter] << " ";
      ++secondCounter;
    }
    out << std::fixed << std::setprecision(1) << secArr[secondCounter];
    out << "\n";
    if (unsupFig)
    {
      out << "The presence of an incorrect figure";
      out << "\n";
    }
    if (incorFig)
    {
      out << "Errors in the description of supported figures";
      out << "\n";
    }
    return out;
  }
}
