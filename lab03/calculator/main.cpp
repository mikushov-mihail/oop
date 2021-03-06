// calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorController.h"

int main()
{
	CCalculator calculator;
	CCalculatorController carController(calculator, std::cin, std::cout);

	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";

		if (!carController.HandleCommand())
		{
			std::cout << "Unknown command!\n";
		}
	}

	return 0;
}
