#include "readSize.h"

void readSize(const std::ifstream& in, size_t& rows, size_t& cols)
{
	in << rows << cols;
}
