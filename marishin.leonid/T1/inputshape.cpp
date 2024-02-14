#include "inputshape.hpp"

void marishin::readRectangle(std::istream& in, Shape** currentShapes, size_t& shapeCount)
{
  const size_t num = 4;
  double option[num] = {};
  for (size_t j = 0; j < num; j++)
  {
    in >> option[j];
  }

  if (!in)
  {
    cleanupShapes(currentShapes, shapeCount);
    throw std::invalid_argument("Invalid rectangle parameters");
  }
  currentShapes[shapeCount] = new Rectangle({ option[0], option[1] }, { option[2], option[3] });
}

void marishin::readTriangle(std::istream& in, Shape** currentShapes, size_t& shapeCount)
{
  const size_t num = 6;
  double option[num] = {};
  for (size_t j = 0; j < num; j++)
  {
    in >> option[j];
  }

  if (!in)
  {
    cleanupShapes(currentShapes, shapeCount);
    throw std::invalid_argument("Invalid triangle parameters");
  }
  currentShapes[shapeCount] = new Triangle({ option[0], option[1] }, { option[2], option[3] }, { option[4], option[5] });
}

void marishin::readRing(std::istream& in, Shape** currentShapes, size_t& shapeCount)
{
  const size_t num = 4;
  double option[num] = {};
  for (size_t j = 0; j < num; j++)
  {
    in >> option[j];
  }

  if (!in)
  {
    cleanupShapes(currentShapes, shapeCount);
    throw std::invalid_argument("Invalid ring parameters");
  }
  currentShapes[shapeCount] = new Ring({ option[0], option[1] }, option[2], option[3]);
}

marishin::Shape* marishin::readShape(std::istream& in, const std::string& currentName, Shape** currentShapes, size_t& shapeCount)
{
  try
  {
    if (currentName == "RECTANGLE")
    {
      readRectangle(in, currentShapes, shapeCount);
    }
    else if (currentName == "TRIANGLE")
    {
      readTriangle(in, currentShapes, shapeCount);
    }
    else if (currentName == "RING")
    {
      readRing(in, currentShapes, shapeCount);
    }
    else
    {
      throw std::invalid_argument("Unknown shape type");
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    continue;
  }
  catch (const std::bad_alloc& e)
  {
    cleanupShapes(currentShapes, shapeCount);
    throw;
  }
}

marishin::Shape** marishin::inputShape(std::istream& in, size_t& shapeCount)
{
  const size_t numShapes = 3;
  std::string shapeNames[numShapes] = { "RECTANGLE", "TRIANGLE", "RING" };
  marishin::Shape** currentShapes = nullptr;
  marishin::Shape** oldShapes = nullptr;
  char symbol = 0;
  std::string currentName = "";

  while (in >> currentName)
  {
    for (size_t i = 0; i < numShapes; ++i)
    {
      if (currentName == shapeNames[i])
      {
        try
        {
          marishin::Shape* newShape = readShape(in, currentName, currentShapes, shapeCount);

          oldShapes = currentShapes;
          currentShapes = new marishin::Shape * [shapeCount + 1];
          if (oldShapes)
          {
            for (size_t k = 0; k < shapeCount; k++)
            {
              currentShapes[k] = oldShapes[k];
            }
          }
          delete[] oldShapes;

          currentShapes[shapeCount] = newShape;
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

    if (currentName == "SCALE")
    {
      break;
    }

    if (!in)
    {
      cleanupShapes(currentShapes, shapeCount);
      throw std::logic_error("It is not shape");
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


void marishin::cleanupShapes(Shape** shapes, size_t& count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}
