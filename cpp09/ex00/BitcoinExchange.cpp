#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(std::string fname) {
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
	if (match != _data.end())
		return match->second;
	match = _data.lower_bound(date);
	if (match != _data.begin())
		return match->second;
	throw PriceNotFoundException();
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
}

void BitcoinExchange::_parseLine(std::ifstream	&infile)
	throw(ErrorReadingFileException) {

	time_t	date;
	double	price;

	date = _parseDate(infile);
	if (!_expectChar(infile, ' ')
		|| !_expectChar(infile, '!')
		|| !_expectChar(infile, ' '))
		throw ErrorReadingFileException();
	if(_data.find(date) != _data.end())
		throw ErrorReadingFileException();
	price = _parsePrice(infile);
	if (!_expectChar(infile, '\n') && !infile.eof())
		throw ErrorReadingFileException();
	_data.insert(std::make_pair(date, price));
}

time_t BitcoinExchange::_parseDate(std::ifstream &infile) const
	throw(ErrorReadingFileException) {

	int			year;
	int			month;
	int			day;
	struct tm	input;
	time_t		result;

	infile >> year;
	if (infile.fail() || infile.gcount() != 4 || !_expectChar(infile, '-'))
		throw ErrorReadingFileException();
	infile >> month;
	if (infile.fail() || infile.gcount() != 2 || !_expectChar(infile, '-'))
		throw ErrorReadingFileException();
	infile >> day;
	if (infile.fail() || infile.gcount() != 2)
	input.tm_year = year - 1900;
	input.tm_mon = month - 1;
	input.tm_mday = day;
	result = mktime(&input);
	if (result == -1)
		throw(ErrorReadingFileException());
	return result;
}

double BitcoinExchange::_parsePrice(std::ifstream &infile) const
	throw(ErrorReadingFileException) {

	double	price;

	infile >> price;
	if (infile.fail() || infile.gcount() == 0)
		throw ErrorReadingFileException();
	return price;
}

bool BitcoinExchange::_expectChar(std::ifstream	&infile, char c) const {
	char res;

	if (!infile.get(&res, 1, '\0').good() || infile.gcount() != 1 || res != c)
		return false;
	return true;
}

const char *BitcoinExchange::PriceNotFoundException::what() const throw() {
	return "No matching price found.";
}

const char *BitcoinExchange::ErrorReadingFileException::what() const throw() {
	return "Error reading file.";
}
