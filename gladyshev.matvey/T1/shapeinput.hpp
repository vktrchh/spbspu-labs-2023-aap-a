#ifndef SHAPEINPUT_HPP
#define SHAPEINPUT_HPP

#include <istream>

namespace gladyshev
{
  std::pair<double *, double *> makeString(std::istream& in, bool& incorFig, bool& unsupFig);
}

#endif
