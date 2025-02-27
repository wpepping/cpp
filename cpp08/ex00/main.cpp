#include <iostream>
#include <list>
#include <string>
#include "easyfind.hpp"

int main(void) {
	int			i;

	std::list<int> 			empty_list;
	std::list<int> 			int_list;
	int_list.push_front(9);
	int_list.push_front(5);
	int_list.push_front(1);

	try {
		i = easyfind(int_list, 9);
		std::cout << "Item found: " << i << std::endl;
	} catch (ValueNotFoundException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		i = easyfind(int_list, 1);
		std::cout << "Item found: " << i << std::endl;
	} catch (ValueNotFoundException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		i = easyfind(int_list, 8);
		std::cout << "Item found: " << i << std::endl;
	} catch (ValueNotFoundException &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		i = easyfind(empty_list, 0);
		std::cout << "Item found: " << i << std::endl;
	} catch (ValueNotFoundException &e) {
		std::cout << e.what() << std::endl;
	}
}
