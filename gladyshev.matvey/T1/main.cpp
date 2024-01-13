#include "memoryallocate.hpp"
#include "shapeinput.hpp"
#include "shapeoutput.hpp"

int main()
{
  using namespace gladyshev;
  double * arrayBeforeScale = nullptr;
  double * arrayAfterScale = nullptr;
  bool incorrectFigure = false;
  bool unsupportedFigure = false;
  try
  {
    std::pair <double*, double*> result = makeString(std::cin, incorrectFigure, unsupportedFigure);
    arrayBeforeScale = result.first;
    arrayAfterScale = result.second;
    outData(std::cout, arrayBeforeScale, arrayAfterScale, incorrectFigure, unsupportedFigure);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error in memory allocating" << "\n";
    return 2;
  }
  delete[] arrayBeforeScale;
  delete[] arrayAfterScale;
  return 0;
}
