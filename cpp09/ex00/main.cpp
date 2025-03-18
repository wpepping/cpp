#include <fstream>
#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"

#define DATABASE_FILE "data.csv"

class BadDateFormatException : std::exception {
public:
	virtual const char* what() const throw() {
		return "bad date format.";
	}
};

class BadNumberFormatException : std::exception {
public:
	virtual const char* what() const throw() {
		return "bad number format.";
	}
};

class IncorrectSeparatorFormatException : std::exception {
public:
	virtual const char* what() const throw() {
		return "incorrect separator format.";
	}
};

class NegativeNumberException : std::exception {
public:
	virtual const char* what() const throw() {
		return "negative number.";
	}
};

class UnexpectedCharacterException : std::exception {
public:
	virtual const char* what() const throw() {
		return "unexpected character at end of line.";
	}
};

class TooLargeNumberException : std::exception {
public:
	virtual const char* what() const throw() {
		return "too large number.";
	}
};

void printLine(const BitcoinExchange exchange, const time_t &date, const double coins) {
	double		value;
	char		date_string[11];
	struct tm	*tm_info;

	tm_info = localtime(&date);
	strftime(date_string, 11, "%Y-%m-%d", tm_info);

	try {
		value = coins * exchange.getBitcoinPrice(date);
		std::cout << date_string << " => " << coins << " => " << value << std::endl;
	} catch (BitcoinExchange::PriceNotFoundException &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void parseLine(const BitcoinExchange &exchange, std::ifstream &infile) {
	time_t		date;
	double		coins;

	try {
		date = BitcoinExchange::Utils::parseDate(infile);
	} catch (BitcoinExchange::ErrorReadingFileException &e) {
		throw BadDateFormatException();
	}

	if (!BitcoinExchange::Utils::expectChar(infile, ' ') ||
		!BitcoinExchange::Utils::expectChar(infile, '|') ||
		!BitcoinExchange::Utils::expectChar(infile, ' '))
		throw IncorrectSeparatorFormatException();

	try {
		coins = BitcoinExchange::Utils::parsePrice(infile);
	} catch (BitcoinExchange::ErrorReadingFileException &e) {
		throw BadNumberFormatException();
	}
	if (coins < 0)
		throw NegativeNumberException();
	if (coins >= 2147483648)
		throw TooLargeNumberException();
	if (!BitcoinExchange::Utils::expectChar(infile, '\n') && !infile.eof())
		throw UnexpectedCharacterException();

	printLine(exchange, date, coins);
}

void processFile(const BitcoinExchange &exchange, const std::string &fname) {
	(void)fname;
	std::ifstream	infile;
	std::string		line;

	infile.open(fname.c_str());
	if (infile.fail()) {
		std::cout << "Error opening file." << std::endl;
		return ;
	} else {
		std::getline(infile, line);
		infile.peek();
		while (infile.peek() != -1 && !infile.eof()) {
			try {
				parseLine(exchange, infile);
			} catch (BadDateFormatException &e) {
				std::cout << "Error: " << e.what() << std::endl;
				std::getline(infile, line);
			} catch (BadNumberFormatException &e) {
				std::cout << "Error: " << e.what() << std::endl;
				std::getline(infile, line);
			} catch (IncorrectSeparatorFormatException &e) {
				std::cout << "Error: " << e.what() << std::endl;
				std::getline(infile, line);
			} catch (NegativeNumberException &e) {
				std::cout << "Error: " << e.what() << std::endl;
				std::getline(infile, line);
			} catch (UnexpectedCharacterException &e) {
				std::cout << "Error: " << e.what() << std::endl;
				std::getline(infile, line);
			} catch (TooLargeNumberException &e) {
				std::cout << "Error: " << e.what() << std::endl;
				std::getline(infile, line);
			}
		}
	}
	infile.close();
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Invalid arguments" << std::endl;
		return 1;
	}

	BitcoinExchange exchange(DATABASE_FILE);
	std::cout << exchange.size() << " prices read." << std::endl;
	processFile(exchange, argv[1]);
}
