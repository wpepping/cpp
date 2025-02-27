#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;

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
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	MutantStack<int>::const_iterator cit = mstack.begin();
	MutantStack<int>::const_iterator cite = mstack.end();
	while (cit != cite)
		std::cout << *(cit++) << std::endl;

	std::stack<int> s(mstack);
	mstack.top()++;
	std::cout << mstack.top() << std::endl;
	std::cout << s.top() << std::endl;

	std::cout << std::endl << "-----------------------------" << std::endl << std::endl;

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
	std::list<int>::iterator list_ite = my_list.end();

	++list_it;
	--list_it;
	while (list_it != list_ite)
	{
		std::cout << *list_it << std::endl;
		++list_it;
	}

	std::list<int>::const_iterator clist_it = my_list.begin();
	std::list<int>::const_iterator clist_ite = my_list.end();
	while (clist_it != clist_ite)
		std::cout << *(clist_it++) << std::endl;

	std::list<int> l(my_list);
	my_list.back()++;
	std::cout << my_list.back() << std::endl;
	std::cout << l.back() << std::endl;

	std::cout << std::endl << "-----------------------------" << std::endl << std::endl;

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
		std::cout << *(rit++) << std::endl;

	std::cout << std::endl;

	MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = mstack.rend();
	while (crit != crite)
		std::cout << *(crit++) << std::endl;

	return 0;
}
