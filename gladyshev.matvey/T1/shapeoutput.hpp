#ifndef SHAPEOUTPUT_HPP
#define SHAPEOUTPUT_HPP

#include <ostream>

namespace gladyshev
{
  std::ostream& outData(std::ostream& out, const double * firstArr, const double * secArr, bool incorFig, bool unsupFig);
}

#endif
