// httpUrl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CUrlParsingError.h"
#include "CHttpUrl.h"

void HandleUserCommand(std::istream& input, std::ostream& output)
{
	std::string commandLine;
	
	output << "> ";

	while (std::getline(input, commandLine))
	{
		try
		{
			CHttpUrl httpUrl(commandLine);

			std::cout << httpUrl << "\n";
		}
		catch (std::exception const& err)
		{
			std::cout << err.what() << "\n";
		}
		output << "> ";
	}
}
#include <sstream>

int main()
{
	CHttpUrl url("http://google.com/doc");
	std::stringstream strm;
	std::cout << url;
	try
	{
		//CHttpUrl url("google.com", "", Protocol::HTTP, 65536);
	}
	catch (CUrlParsingError const& e)
	{
		std::cout << e.what() << "\n";
	}
	catch (std::exception const& e)
	{
		//std::cout << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "other excpetion\n";
	}

	try
	{
		//CHttpUrl url("https://google.com");
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << "\n";
	}
	//HandleUserCommand(std::cin, std::cout);
	/*try
	{
		throw CUrlParsingError("invalid url");
	}
	catch (CUrlParsingError const& err)
	{
		std::cout << "url is" << err.what() << "\n";
	}
	catch (std::exception const& err)
	{
		std::cout << err.what() << "\n";
	}*/
	return 0;
}

