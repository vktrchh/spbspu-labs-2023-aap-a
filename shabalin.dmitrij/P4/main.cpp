#include <iostream>
#include <fstream>
#include <cctype>
#include <cstddef>
#include <stdexcept>

void matrixInput(std::ifstream& input, int* matrix, size_t countOfElements)
{
    for (size_t i = 0; i < countOfElements; ++i)
    {
        if (!(input >> matrix[i]))
        {
            throw std::logic_error("Can't input the matrix");
        }
    }
};

void matrixOutput(std::ofstream& output, const double* matrix, size_t rows, size_t cols)
{
    if (!(output << rows << ' ' << cols))
    {
        throw std::logic_error("Can't output the result");
    }
    for (size_t i = 0; i < rows * cols; ++i)
    {
        if (!(output << ' ' << matrix[i]))
        {
            throw std::logic_error("Can't output the result");
        }
    }
};

double* makeUpSmoothMatrix(int* matrix, double* smooth, size_t rows, size_t cols)
{
    for (size_t i = 0; i < cols * rows; ++i)
    {
        double sum = 0.0;
        size_t count = 0;
        size_t row = i / cols;
        size_t col = i % cols;
        for (int j = -1; j <= 1; ++j)
        {
            for (int k = -1; k <= 1; ++k)
            {
                if (!(j == 0 && k == 0))
                {
                    size_t newRow = row + j;
                    size_t newCol = col + k;
                    if ((newRow < rows) && (newCol < cols))
                    {
                        size_t index = newRow * cols + newCol;
                        sum += matrix[index];
                        count++;
                    }
                }
            }
        }
        smooth[i] = sum / count;
    }
    return smooth;
};

size_t findLargeSeriesOfEqualElements(int* matrix, size_t rows, size_t cols)
{
    size_t numberSeries = 1;
    size_t maximumNumberSeries = 0;
    size_t rowNum = 0;
    for (int i = 0; i < rows * cols; ++i)
    {
        if (matrix[i] == matrix[i + 1])
        {
            numberSeries += 1;
        }
        if (numberSeries > maximumNumberSeries)
        {
            maximumNumberSeries = numberSeries;
            rowNum = i / cols + 1;
        }
    }
    return rowNum;
};

int main(int argc, char* argv[])
{

    if (argc != 4)
    {
        std::cerr << "Error in command line arguments" << "\n";
        return 1;
    }

    int task = std::atoi(argv[1]);

    if (!((task == 2) || (task == 1)))
    {
        std::cerr << "Number of task is out of range" << "\n";
        return 2;
    }

    std::ifstream input(argv[2]);
    if (!input)
    {
        std::cerr << "Cannot read a number" << "\n";
        return 2;
    }

    std::ofstream output(argv[3]);
    if (!output)
    {
        std::cerr << "Error: Output file is not open" << "\n";
        return 2;
    }

    size_t rows = 0;
    size_t cols = 0;

    if (!(input >> rows) || !(input >> cols))
    {
        std::cerr << "Can't read rows or columns" << "\n";
        return 2;
    }

    if ((rows == 0 && cols == 0))
    {
        std::cerr << "Null matrix" << "\n";
        return 0;
    }

    size_t countOfElements = rows * cols;

    int tempMatrix[10000] = {};
    double tempSmoothedMatrix[10000] = {};

    int* matrix = nullptr;
    double* smoothedMatrix = nullptr;

    if (task == 2)
    {
        try
        {
            matrix = new int[countOfElements];
            smoothedMatrix = new double[countOfElements];
        }
        catch (const std::bad_alloc& e)
        {
            delete[] matrix;
            delete[] smoothedMatrix;
        }
        try
        {
            matrixInput(input, matrix, countOfElements);
            output << findLargeSeriesOfEqualElements(matrix, rows, cols) << ' ';
            if (!output)
            {
                throw std::logic_error("Error of output");
            }
            //smoothedMatrix = makeUpSmoothMatrix(matrix, smoothedMatrix, rows, cols);
            //matrixOutput(output, smoothedMatrix, rows, cols);
            //delete[] matrix;
            //delete[] smoothedMatrix;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            delete[] matrix;
            delete[] smoothedMatrix;
            return 1;
        }
    }
    else if (task == 1)
    {
        try
        {
            matrixInput(input, tempMatrix, countOfElements);
            output << findLargeSeriesOfEqualElements(tempMatrix, rows, cols) << ' ';
            if (!output)
            {
                throw std::logic_error("Error of output");
            }
            //smoothedMatrix = makeUpSmoothMatrix(tempMatrix, tempSmoothedMatrix, rows, cols);
            //matrixOutput(output, tempSmoothedMatrix, rows, cols);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }
    }
}
