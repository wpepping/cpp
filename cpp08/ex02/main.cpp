#include "MutantStack.hpp"
#include <iostream>
#include <list>

template<typename T>
void print_it(T begin, T end) {
	while (begin != end)
	{
		std::cout << *begin << std::endl;
		++begin;
	}
}

int main()
{
	MutantStack<int> mstack;

	std::cout << "-----------------------------" << std::endl;
	std::cout << "- WITH MUTANT STACK         -" << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	print_it<MutantStack<int>::iterator>(mstack.begin(), mstack.end());

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();

	++it;
	--it;

	print_it<MutantStack<int>::iterator>(it, mstack.end());
	print_it<MutantStack<int>::const_iterator>(mstack.begin(), mstack.end());

	std::stack<int> s(mstack);
	mstack.top()++;
	std::cout << mstack.top() << std::endl;
	std::cout << s.top() << std::endl;

	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "- WITH LIST                 -" << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::list<int> my_list;

	my_list.push_back(5);
	my_list.push_back(17);

	std::cout << my_list.back() << std::endl;

	my_list.pop_back();
	std::cout << my_list.size() << std::endl;

	my_list.push_back(3);
	my_list.push_back(5);
	my_list.push_back(737);

	my_list.push_back(0);

	std::list<int>::iterator list_it = my_list.begin();

	print_it<std::list<int>::iterator>(list_it, my_list.end());
	print_it<std::list<int>::const_iterator>(my_list.begin(), my_list.end());

	std::list<int> l(my_list);
	my_list.back()++;
	std::cout << my_list.back() << std::endl;
	std::cout << l.back() << std::endl;

	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "- REVERSE ITERATORS         -" << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	print_it<MutantStack<int>::reverse_iterator>(mstack.rbegin(), mstack.rend());

	std::cout << std::endl;

	print_it<MutantStack<int>::const_reverse_iterator>(mstack.rbegin(), mstack.rend());

	return 0;
}
