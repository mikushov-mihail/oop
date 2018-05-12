// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Math.h"

void HandleUserCommand(std::istream &input, std::ostream& output)
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	double d = 0.0;
	double e = 0.0;

	output << "> ";

	while (input >> a >> b >> c >> d >> e)
	{
		try
		{
			output << Solve4(a, b, c, d, e) << std::endl;
		}
		catch (std::exception const& err)
		{
			std::cout << err.what() << std::endl;
		}
	
		output << "> ";
	}
}

int main()
{
	//std::cout << Solve3(1, 1, -1, -1);
	//std::cout << Solve3(-3.0, 45.0, 4.0, -5.0);
	//std::cout << Solve3(1.0, -9.0, 15.0, 25.0);
	//std::cout << Solve3(1.0, -6, 5.0, -12.0);
	//std::cout << Solve3(1.0, -6.0, 675.0, -12.0);
	//std::cout << Solve3(1.0, 3.0, 3.0, 12.0);
	//HandleUserCommand(std::cin, std::cout);
	auto result = Solve4(1, 4, -4, -20, -5);
	std::cout << result << std::endl;
    return 0;
}

