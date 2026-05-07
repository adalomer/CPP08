#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 5; ++i)
		vec.push_back(i * 2);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 4);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Vector error: " << e.what() << std::endl;
	}

	std::list<int> lst;
	for (int i = 1; i <= 5; ++i)
		lst.push_back(i);

	try
	{
		std::list<int>::const_iterator it = easyfind(lst, 3);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "List error: " << e.what() << std::endl;
	}

	return 0;
}
