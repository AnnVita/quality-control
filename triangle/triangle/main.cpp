#include "stdafx.h"
#include "CTriangleHandleError.h"

static const size_t NECESSARY_NUMBER_OF_ARGUMENTS = 4;

bool CheckStringWithNumber(const std::string & subject);
bool CheckTriangleExistance(const std::vector<double> & sides);
bool CheckTriangleIsosceles(const std::vector<double> & sides);
bool CheckTriangleEquilateral(const std::vector<double> & sides);

int main(int argc, char * argv[])
{
	try
	{
		if (argc != NECESSARY_NUMBER_OF_ARGUMENTS)
		{
			throw CTriangleHandleError("Too few arguments on the command line!");
		}

		std::vector<double> sides(3);

		for (int i = 1; i < argc; i++)
		{
			if (!CheckStringWithNumber(argv[i]))
			{
				throw CTriangleHandleError("One of arguments has invalid value!");
			}
			sides[i - 1] = atof(argv[i]);
		}

		std::sort(sides.begin(), sides.end());
		std::string answer;

		if (CheckTriangleExistance(sides))
		{
			answer = "This is a usial triangle";
			if (CheckTriangleIsosceles(sides))
			{
				answer = "This is an isosceles triangle";
			}
			if (CheckTriangleEquilateral(sides))
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

bool CheckStringWithNumber(const std::string & subject)
{
	std::regex numberCheckingRegex("[0-9]{1,10}([.]{0,1})?([0-9]{0,2})?");
	return std::regex_match(subject, numberCheckingRegex);
}

bool CheckTriangleExistance(const std::vector<double> & sides)
{
	return ((sides[0] != 0) && (sides[1] != 0) && (sides[2] != 0) &&
		(sides[0] + sides[1] > sides[2]) && (sides[0] + sides[2] > sides[1]) && (sides[1] + sides[2] > sides[0]));
}

bool CheckTriangleIsosceles(const std::vector<double> & sides)
{
	return ((sides[1] == sides[2]) || (sides[1] == sides[0]) || (sides[2] == sides[0]));
}

bool CheckTriangleEquilateral(const std::vector<double> & sides)
{
	return ((sides[1] == sides[2]) && (sides[1] == sides[0]) && (sides[2] == sides[0]));
}