#include "inputshape.hpp"

marishin::Shape** marishin::inputShape(std::istream& in, size_t& shapeCount)
{
  const size_t NUM_SHAPES = 3;
  const std::string shapeNames[NUM_SHAPES] = { "RECTANGLE", "TRIANGLE", "RING" };
  const size_t shapeParametrsCount[NUM_SHAPES] = { 4, 6, 4};

  Shape** shapeArray = nullptr;
  char symbol = 0;

  while (true)
  {

  }
}
