#include <iostream>
#include <string>
#include "iter.hpp"

template<typename T>
void cout(T arg) {
	std::cout << arg << std::endl;
}

int main(void) {
	int emptyArray[] = {};
	int intArray[] = {1, 2, 3, 4, 5};
	std::string stringArray[] = {"Hello", "World!"};
	char *c = NULL;

	iter<int>(emptyArray, 0, &cout<int>);
	iter<int>(intArray, 5, &cout<int>);
	iter<std::string>(stringArray, 2, &cout<std::string>);
	iter<char>(c, 0, &cout<char>);
}
