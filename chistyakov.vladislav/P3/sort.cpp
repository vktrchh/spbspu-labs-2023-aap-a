#include "sort.hpp"
#include "numOfOccurOfLetters.hpp"

char* chistyakov::sortingCertainNumnerOfItems(char* array, char* result, size_t lenght)
{
  for (size_t i = 1; i < lenght; ++i)
  {
    char timeValue = 0;
    char isSort = 1;
    for (size_t j = 0; j < lenght - i; ++j)
    {
      if (array[j] > array[j + 1])
      {
        timeValue = array[j + 1];
        array[j + 1] = array[j];
        array[j] = timeValue;
        isSort = 0;
      }
    }
    if (isSort)
    {
      break;
    }
  }

  for (size_t i = 0; i < lenght; ++i)
  {
    result[i] = array[i];
  }

  return result;
}

void chistyakov::sortingByQuantity(const char* array, char* chars, size_t* nums)
{
  numOfOccurOfLetters(array, chars, nums);

  size_t lenght = 0;
  while (nums[lenght] != 0)
  {
    lenght++;
  }

  for (size_t i = 1; i < lenght; ++i)
  {
    size_t timeValueNum = 0;
    char timeValueChar = 0;
    char isSort = 1;
    for (size_t j = 0; j < lenght - i; ++j)
    {
      if (nums[j] < nums[j + 1] && nums[j + 1] != 0)
      {
        timeValueNum = nums[j + 1];
        nums[j + 1] = nums[j];
        nums[j] = timeValueNum;

        timeValueChar = chars[j + 1];
        chars[j + 1] = chars[j];
        chars[j] = timeValueChar;

        isSort = 0;
      }
    }
    if (isSort)
    {
      break;
    }
  }
}
