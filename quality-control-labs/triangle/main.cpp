#include "stdafx.h"
#include "CTriangleHandleError.h"
#include <array>

static const size_t NECESSARY_NUMBER_OF_ARGUMENTS = 4;

int main(int argc, char * argv[])
{
	try
	{
		if (argc != NECESSARY_NUMBER_OF_ARGUMENTS)
		{
			throw CTriangleHandleError("Invalid number of command-line arguments. Input format: triangle.exe a b c");
		}

		std::vector<double> sides(3);
		std::regex numberCheckingRegex("[0-9]{1,10}([.]{0,1})?([0-9]{0,4})?");

		for (int i = 1; i < argc; i++)
		{
			if (!std::regex_match(argv[i], numberCheckingRegex))
			{
				throw CTriangleHandleError("One of arguments has invalid value. Please, check the entered numbers.");
			}
			sides[i - 1] = atof(argv[i]);
		}

		std::sort(sides.begin(), sides.end());
		std::string answer;

		if ((sides[0] != 0) && (sides[1] != 0) && (sides[2] != 0) &&
			(sides[0] + sides[1] > sides[2]) && (sides[0] + sides[2] > sides[1]) && (sides[1] + sides[2] > sides[0]))
		{
			answer = "This is a usial triangle";
			if ((sides[1] == sides[2]) || (sides[1] == sides[0]) || (sides[2] == sides[0]))
			{
				answer = "This is an isosceles triangle";
			}
			if ((sides[1] == sides[2]) && (sides[1] == sides[0]) && (sides[2] == sides[0]))
			{
				answer = "This is an equilateral triangle";
			}
		}
		else
		{
			answer = "This is not a triangle";
		}
		std::cout << answer << std::endl;
		return 0;
	}
	catch (CTriangleHandleError const & e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
}