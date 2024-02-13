#include "findLargeSeriesofElements.hpp"

int shabalin::findLargeSeriesOfEqualElements(const int* matrix, size_t rows, size_t cols)
{
    size_t numberSeries = 0;
    size_t maximumNumberSeries = 0;
    size_t rowNumber = 0;
    for (size_t i = 0; i < rows * cols - 1; ++i)
    {
        if (matrix[i] == matrix[i + 1])
        {
            numberSeries += 1;
        }
        if (numberSeries > maximumNumberSeries)
        {
            maximumNumberSeries = numberSeries;
            rowNumber = (i / cols) + 1;
        }
    }
    return rowNumber;
};
