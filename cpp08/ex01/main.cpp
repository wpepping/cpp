#include <iostream>
#include <list>
#include "Span.hpp"

void getSpans(Span sp) {
	try {
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	} catch (Span::UnableToComplyException &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (Span::UnableToComplyException &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	getSpans(sp);

	Span sp1 = Span(1);

	getSpans(sp1);

	sp1.addNumber(1);

	getSpans(sp1);

	try {
		sp1.addNumber(2);
		std::cout << "ERROR: Adding more numbers than max size succeeded" << std::endl;
	} catch (Span::CapacityLimitReachedException &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::list<int> int_list;

	Span sp2(10001);
	srand(time(0));
	for (int i = 0; i < 10000; i++)
		int_list.push_back(rand());

	sp2.addNumbers<std::list<int> >(int_list.begin(), int_list.end());

	std::cout << "Span size: " << sp2.size() << std::endl;
	getSpans(sp2);

	std::list<int> int_list2;
	int_list2.push_back(0);
	int_list2.push_back(1);

	try {
		sp2.addNumbers<std::list<int> >(int_list.begin(), int_list.end());
		std::cout << "ERROR: Adding more numbers than max size succeeded" << std::endl;
	} catch (Span::CapacityLimitReachedException &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
