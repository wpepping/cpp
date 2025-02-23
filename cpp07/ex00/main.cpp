#include <iostream>
#include "whatever.hpp"

int main(void) {
	int i = 5;
	int j = 9;

	swap(i, j);
	std::cout << "i = " << i << ", j = " << j << std::endl;
	std::cout << "max = " << max<int>(i, j) << ", min = " << min<int>(i, j) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}
