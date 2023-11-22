#include <iostream>
#include <limits>
#include <stdexcept>

class Dict()
{
  Dict(char simvol)
  {
    simvol_(simvol),
    counter_(0)
  }

  public:
    void operator()(char simvol)
    {
      size_t max_size = std::numeric_limits< size_t >::max();
      if (counter_ == max_size)
      {
        std::cerr << "The number of this symbol is too large\n";
      }
      else
      {
        counter_++;
      }
    }

    size_t operator()() const
    {
      return counter_;
    }

  private:
    size_t counter_;
    char simvol_;
};

char * enlargeArray(char * array, size_t size)
{
  char * newArray = new char[size + 10]{};

  try
  {
    for (size_t i = 0; i < size; ++i)
    {
      newArray[i] = array[i];
    }
    delete [] array;
    return newArray;
  }
  catch (std::logic_error & e)
  {
    std::cerr << e.what() << "\n";
    delete [] newArray;
    return nullptr;
  }
}

bool overflow(size_t number)
{
  size_t max_size = std::numeric_limits< size_t >::max();
  return number == max_size;
}

char * frqTop(char * array, size_t size)
{
  
}

int main()
{
  size_t size = 10;
  char * array = new char[size]{};

  char input = 0;
  size_t i = 0;
  std::cin >> std::noskipws;

  while ((std::cin >> input) && (i < size))
  {
    if (input == '\n')
    {
      break;
    }
    else if (!std::cin)
    {
      std::cerr << "Bad input!\n";
      delete [] array;
      return 1;
    }

    if (overflow(i) || overflow(size))
    {
      delete [] array;
      std::cerr << "Sequecne is too long\n";
      return 2;
    }

    array[i++] = input;

    if (i == size)
    {
      do
      {
        array = enlargeArray(array, size);
      }
      while (array != nullptr);

      size += 10;
    }
  }

  std::cin >> std::skipws;

  for (size_t i = 0; i < size; ++i)
  {
    std::cout << array[i];
  }
  return 0;
}

