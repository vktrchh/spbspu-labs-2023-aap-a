#include <exception>
#include <iostream>
#include <stdexcept>
#include <cctype>

char * inputArray(size_t & arrSize);

int main()
{
  size_t arrSize = 0;
  char * outString = nullptr;
  try {
    outString = inputArray(arrSize);
    std::cout << outString << "\n";
  } catch (const std::exception & e) {
    std::cerr << "Error: " << e.what() << "\n";
    delete [] outString;
    return 1;
  }

}


char * inputArray(size_t & arrSize)
{
  const size_t defBufferSize = 10;
  arrSize = defBufferSize;

  size_t index = 0;
  char sym = 0;

  char * mainBuffer = new char[arrSize];
  if (!mainBuffer)
  {
    throw std::logic_error("Can't create mainBuffer");
  }

  while ((std::cin >> sym) && sym != '\n')
  {
    if (index == arrSize - 1)
    {
      arrSize *= 2;
      
      char * tempBuffer = new char[arrSize];
      if (!tempBuffer)
      {
        throw std::logic_error("Cant't create tempBuffer");
      }

      for (size_t j = 0; j < index; j++)
      {
        tempBuffer[j] = mainBuffer[j];
      }
      
      delete [] mainBuffer;

      mainBuffer = tempBuffer;
    }
    mainBuffer[index] = sym;
  }
  
  return mainBuffer;
}
