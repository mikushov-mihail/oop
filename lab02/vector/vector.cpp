// vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ProccessesVector.h"

void VectorHandle(std::istream &input, std::ostream &output);

int main()
{
	VectorHandle(std::cin, std::cout);

	return 0;
}

void VectorHandle(std::istream &input, std::ostream &output)
{
	std::vector<double> number = ReadVector(input);
	ProcessVector(number);
	std::sort(number.begin(), number.end());
	PrintVector(output, number);
}
