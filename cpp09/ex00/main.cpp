#include <fstream>
#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Invalid arguments" << std::endl;
		return 1;
	}

	BitcoinExchange exchange(argv[1]);
}
