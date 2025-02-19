#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	int i;
	Base* result;

	i = rand() % 3;
	switch (i) {
		case 0:
			result = new A();
			break;
		case 1:
			result = new B();
			break;
		case 2:
			result = new C();
	}
	return (result);
}

void identify(Base* p) {
	Base* b;

	b = dynamic_cast<A *>(p);
	if (b)
		std::cout << "A" << std::endl;
	b = dynamic_cast<B *>(p);
	if (b)
		std::cout << "B" << std::endl;
	b = dynamic_cast<C *>(p);
	if (b)
		std::cout << "C" << std::endl;

}

void identify(Base& p) {
	try {
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) { }
	try {
		dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &e) { }
	try {
		dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception &e) { }
}

int main(void) {
	Base *b;

	srand(time(0));
	for (int i = 0; i < 10; i++) {
		b = generate();
		identify(b);
		identify(*b);
		delete b;
	}
}
