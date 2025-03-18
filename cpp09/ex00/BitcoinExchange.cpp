#include "BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::Utils::Utils() { }

BitcoinExchange::Utils::~Utils() { }

time_t BitcoinExchange::Utils::parseDate(std::ifstream &infile)
	throw(ErrorReadingFileException) {

	int			year;
	int			month;
	int			day;
	time_t		result;

	infile >> year;
	if (infile.fail() || !Utils::_between(year, 1900, 9999) || !expectChar(infile, '-')) {
		infile.clear();
		throw ErrorReadingFileException();
	}
	infile >> month;
	if (infile.fail() || !_between(month, 1, 12) || !expectChar(infile, '-')) {
		infile.clear();
		throw ErrorReadingFileException();
	}
	infile >> day;
	if (infile.fail() || !_between(day, 1, 31)) {
		infile.clear();
		throw ErrorReadingFileException();
	}

	result = Utils::_getDate(year, month, day);
	if (result == -1)
		throw(ErrorReadingFileException());
	return result;
}

double BitcoinExchange::Utils::parsePrice(std::ifstream &infile)
	throw(ErrorReadingFileException) {

	double	price;

	infile >> price;
	if (infile.fail()) {
		infile.clear();
		throw ErrorReadingFileException();
	}
	return price;
}

bool BitcoinExchange::Utils::expectChar(std::ifstream	&infile, char c) {
	if (infile.peek() != c)
		return false;
	infile.get();
	return true;
}

time_t BitcoinExchange::Utils::_getDate(int year, int month, int day) {
	struct tm	input = {};

	input.tm_year = year - 1900;
	input.tm_mon = month - 1;
	input.tm_mday = day;
	return mktime(&input);
}

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(std::string fname) throw(ErrorReadingFileException) {
	_initDb(fname);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
	_data = src._data;
}

BitcoinExchange::~BitcoinExchange() { }

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
	if (this != &src)
		_data = src._data;
	return *this;
}

double BitcoinExchange::getBitcoinPrice(const time_t &date) const
	throw(PriceNotFoundException) {

	std::map<time_t, double>::const_iterator match;
	match = _data.find(date);
	match = _data.lower_bound(date);
	if (match == _data.begin())
		throw PriceNotFoundException();
	return (--match)->second;
}

void BitcoinExchange::_initDb(const std::string &fname)
	throw(ErrorReadingFileException) {

	std::ifstream	infile;
	std::string		line;

	infile.open(fname.c_str());
	if (infile.fail())
		throw ErrorReadingFileException();
	std::getline(infile, line);
	infile.peek();
	while (!infile.eof()) {
		_parseLine(infile);
		infile.peek();
	}
	infile.close();
}

void BitcoinExchange::_parseLine(std::ifstream	&infile)
	throw(ErrorReadingFileException) {

	time_t	date;
	double	price;

	date = Utils::parseDate(infile);
	if (!Utils::expectChar(infile, ','))
		throw ErrorReadingFileException();
	if(_data.find(date) != _data.end())
		throw ErrorReadingFileException();
	price = Utils::parsePrice(infile);
	if (!Utils::expectChar(infile, '\n') && !infile.eof())
		throw ErrorReadingFileException();
	_data.insert(std::make_pair(date, price));
}

int BitcoinExchange::size() const {
	return _data.size();
}

const char *BitcoinExchange::PriceNotFoundException::what() const throw() {
	return "No matching price found.";
}

const char *BitcoinExchange::ErrorReadingFileException::what() const throw() {
	return "Error reading file.";
}
