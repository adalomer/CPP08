#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	std::list<int> lst;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		lst.push_back(*it);

	std::cout << "List size: " << lst.size() << std::endl;
	return 0;
}
