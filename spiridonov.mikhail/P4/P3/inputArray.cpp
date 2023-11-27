#include <iostream>
#include "seqsym.hpp"
#include "inputArray.hpp"

using namespace spiridonov;

void spiridonov::extencionArray(const size_t * outdatedArray, size_t * actualArray, size_t str)
{
  for (size_t i = 0; i < str; i++)
  {
    actualArray[i] = outdatedArray[i];
  }
  delete[] outdatedArray;
}

size_t * spiridonov::inputArray(const size_t* outdatedArray, size_t * currArray, const size_t str)
{
  size_t * actualArray = new size_t[*currArray += 5];
  spiridonov::extencionArray(outdatedArray, actualArray, str);
 // char* outdatedArray = new char[str];


  if (!currArray)
  {
    std::cerr << "Error to create array" << "\n";
  }
  char character = 0;
  size_t i = 0;

  while  ((character != '\n') && (i < str + 5) && (std::cin >> character))
  {
    std::cin >> character;
    actualArray[i] = character;
    i++;

    if (i == str - 1)
    {
      spiridonov::extencionArray(outdatedArray, currArray, str);
    }
  }
  //str = i;
  actualArray[i] = '\n';
  return actualArray;
  //str = i;
  //return spiridonov::inputArray(str);
}
