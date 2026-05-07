#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
	Span sp(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	Span big(10000);
	std::vector<int> values;
	values.reserve(10000);
	for (int i = 0; i < 10000; ++i)
		values.push_back(i * 3);

	try
	{
		big.addRange(values.begin(), values.end());
		std::cout << "Big shortest: " << big.shortestSpan() << std::endl;
		std::cout << "Big longest: " << big.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Big error: " << e.what() << std::endl;
	}

	return 0;
}
