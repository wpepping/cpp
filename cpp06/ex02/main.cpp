#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	switch (rand() % 3) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
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
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) { }
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &e) { }
	try {
		(void)dynamic_cast<C &>(p);
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
