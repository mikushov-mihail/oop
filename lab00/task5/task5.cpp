// task5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool StringToDouble(const string &str, double& result)
{
	try
	{
		result = stod(str);
	}
	catch (const invalid_argument &e)
	{
		cerr << e.what() << "\n";
		return false;
	}
	catch (const out_of_range &e)
	{
		cerr << e.what() << "\n";
		return false;
	}

	return true;
}

const double PI = 3.141592653;
const double G = 9.8;

double DegreeToRadian(double deg)
{
	return (deg * PI / 180);
}

double CalcDistance(double v0, double a0)
{
	return v0 * v0 * cos(2 * DegreeToRadian(a0)) / G;
}

void HandleCommand(istream& input, ostream& output)
{
	string commandLine;
	while (true)
	{
		output << "Enter a0 (or type 'exit')> ";
		getline(input, commandLine);
		if (commandLine == "exit")
		{
			break;
		}

		double a0 = 0.0;

		if (StringToDouble(commandLine, a0))
		{
			output << "Enter v0 (or type 'exit')> ";
			getline(input, commandLine);
			if (commandLine == "exit")
			{
				break;
			}

			double v0 = 0.0;
			if (StringToDouble(commandLine, v0))
			{
				double distance = CalcDistance(v0, a0);
				output << "Distance is: " << distance << "\n";
			}
		}
	}

	output << "Goodbye\n";
}

int main()
{
	HandleCommand(cin, cout);
    
	return 0;
}

