#include "inputshape.hpp"

marishin::Shape** marishin::inputShape(std::istream& in, size_t& shapeCount)
{
  const size_t numShapes = 3;
  const std::string shapeNames[numShapes] = { "RECTANGLE", "TRIANGLE", "RING" };
  const size_t shapeParametersCount[numShapes] = { 4, 6, 4 };

  Shape** shapes = nullptr;
  char symbol = 0;
  while (in)
  {
    try
    {
      std::string currentName;
      in >> currentName;

      if (currentName == "SCALE")
      {
        break;
      }

      bool validShape = false;
      size_t shapeIndex = 0;

      for (size_t i = 0; i < numShapes; ++i)
      {
        if (currentName == shapeNames[i])
        {
          validShape = true;
          shapeIndex = i;
          break;
        }
      }

      if (!validShape)
      {
        std::cerr << "Invalid shape";
        cleanupShapes(newShapes, shapeCount);
        throw;
      }

      double* parameters = new double[shapeParametersCount[shapeIndex]];

      for (size_t j = 0; j < shapeParametersCount[shapeIndex]; j++)
      {
        in >> parameters[j];
      }

      if (!in)
      {
        std::cerr << "Invalid arguments";
        cleanupShapes(newShapes, shapeCount);
        delete[] parameters;
        throw;
      }

      Shape** newShapes = new Shape*[shapeCount + 1];

      if (shapes)
      {
        for (size_t k = 0; k < shapeCount; k++)
        {
          newShapes[k] = shapes[k];
        }
        delete[] shapes;
      }

        if (currentName == "RECTANGLE")
        {
          newShapes[shapeCount] = new Rectangle({ parameters[0], parameters[1] }, { parameters[2], parameters[3] });
        }
        else if (currentName == "TRIANGLE")
        {
          newShapes[shapeCount] = new Triangle({ parameters[0], parameters[1] }, { parameters[2], parameters[3] }, { parameters[4], parameters[5] });
        }
        else if (currentName == "RING")
        {
          newShapes[shapeCount] = new Ring({ parameters[0], parameters[1] }, parameters[2], parameters[3]);
        }
        ++shapeCount;
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Failed to allocate memory for shape";
      delete[] parameters;
      cleanupShapes(newShapes, shapeCount);
      throw;
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }

    shapes = newShapes;
    delete[] parameters;

    in >> std::noskipws;
    while (symbol != '\n')
    {
      in >> symbol;
    }
    in >> std::skipws;
  }

  return shapes;
}

void marishin::cleanupShapes(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}
