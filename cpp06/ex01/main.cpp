#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main(void) {
	Data		d;
	Data		*p;
	uintptr_t	uip;

	d.key = "Hello";
	d.value = "World!";
	p = &d;
	uip = Serializer::serialize(p);
	p = Serializer::deserialize(uip);
	std::cout << p->key << " " << p->value << std::endl;
}
