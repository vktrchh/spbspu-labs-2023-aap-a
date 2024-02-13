#include "inputshape.hpp"

marishin::Shape** marishin::inputShape(std::istream& in, size_t& shapeCount)
{
  size_t numShapes = 3;
  std::string shapeNames[numShapes] = { "RECTANGLE", "TRIANGLE", "RING" };
  size_t shapeParametersCount[numShapes] = { 4, 6, 4 };
  std::string currentName = "";
  marishin::Shape** currentShapes = nullptr;
  marishin::Shape** oldShapes = nullptr;
  char symbol = 0;
  while (in >> currentName)
  {
    for (size_t i = 0; i < numShapes; ++i)
    {
      if (currentName == shapeNames[i])
      {
        double option[shapeParametersCount[i]]{};

        for (size_t j = 0; j < shapeParametersCount[i]; j++)
        {
          in >> option[j];
        }

        if (!in)
        {
          cleanupShapes(currentShapes, shapeCount);
          throw std::invalid_argument("Invalid arguments");
        }

        oldShapes = currentShapes;
        currentShapes = new Shape * [shapeCount + 1];

        if (oldShapes)
        {
          for (size_t k = 0; k < shapeCount; k++)
          {
            currentShapes[k] = oldShapes[k];
          }
        }
        delete[] oldShapes;

        try
        {
          if (currentName == "RECTANGLE")
          {
            currentShapes[shapeCount] = new Rectangle({ option[0], option[1] }, { option[2], option[3] });
          }
          else if (currentName == "TRIANGLE")
          {
            currentShapes[shapeCount] = new Triangle({ option[0], option[1] }, { option[2], option[3] }, { option[4], option[5] });
          }
          else if (currentName == "RING")
          {
            currentShapes[shapeCount] = new Ring({ option[0], option[1] }, option[2], option[3]);
          }
          ++shapeCount;
        }
        catch (const std::bad_alloc& e)
        {
          cleanupShapes(currentShapes, shapeCount);
          throw;
        }
        catch (const std::exception& e)
        {
          std::cerr << e.what() << '\n';
        }
      }
    }

    if (currentName == "")
    {
      std::cerr << "Incorrect input";
    }
    if (currentName == "SCALE")
    {
      break;
    }
    in >> std::noskipws;
    while (symbol != '\n')
    {
      in >> symbol;
    }
    in >> std::skipws;
  }
  return currentShapes;
}

void marishin::cleanupShapes(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}
