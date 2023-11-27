#include <iostream>
#include "inputArray.hpp"

namespace spiridonov
{
  void spiridonov::extencionArray(const size_t* outdatedArray, size_t* actualArray, size_t str)
  {
    for (size_t i = 0; i < str; i++)
    {
      actualArray[i] = outdatedArray[i];
    }
    delete[] outdatedArray;
  }

  size_t* spiridonov::inputArray(const size_t* outdatedArray, size_t* currArray, const size_t str)
  {
    size_t* actualArray = new size_t[*currArray += 5];
    spiridonov::extencionArray(outdatedArray, actualArray, str);

    char character = 0;
    size_t i = str;

    while ((i < str + 5) && (character != '\n'))
    {
      std::cin >> character;
      actualArray[i] = character;
      i++;

      if (i == *currArray - 1)
      {
        *currArray += 5;
        size_t* newArray = new size_t[*currArray];
        spiridonov::extencionArray(actualArray, newArray, i);
        delete[] actualArray;
        actualArray = newArray;
      }
    }
    actualArray[i] = '\n';
    return actualArray;
  }
}
