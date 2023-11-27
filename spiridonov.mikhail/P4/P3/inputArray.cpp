#include <iostream>
#include "inputArray.hpp"

namespace spiridonov
{
  //void spiridonov::extencionArray(const size_t* outdatedArray, size_t* actualArray, size_t& str)
  //{
    //for (size_t i = 0; i < str; i++)
    //{
      //actualArray[i] = outdatedArray[i];
    //}
    //delete[] outdatedArray;
  //}

  size_t * spiridonov::inputArray(std::istream& input, size_t &sizeOfStr)
  {
    size_t* actualArray = new size_t[sizeOfStr];
    //spiridonov::extencionArray(outdatedArray, actualArray, str);

    size_t character = 0;
    size_t i = 0;

    while ((input >> character) && (character != '\n'))
    {
      //std::cin >> character;
      actualArray[i] = character;
      i++;

      if (i == sizeOfStr)
      {
        //character += 5;
        size_t newSize = sizeOfStr + 5;
        size_t * newArray = new size_t[newSize];
        //spiridonov::extencionArray(actualArray, *newArray, size);
        for (size_t j = 0; j < sizeOfStr; ++j)
        {
          newArray[j] = actualArray[j];
        }
        delete[] actualArray;
        actualArray = newArray;
        sizeOfStr = newSize;
      }
    }
    //actualArray[i] = '\n';
    //sizeOfStr = i;
    return actualArray;
  }
}
