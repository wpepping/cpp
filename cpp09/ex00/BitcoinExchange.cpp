#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(std::string fname) {

}

BitcoinExchange::BitcoinExchange(BitcoinExchange &src) {

}

BitcoinExchange::~BitcoinExchange() {

}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &src) const {

}

const double BitcoinExchange::getBitcoinPrice(const std::string &date) const {

}

void BitcoinExchange::_initDb(const std::string &fname) {

}

bool BitcoinExchange::_storePrice(const std::string &line) {

}

const char *BitcoinExchange::PriceNotFoundException::what() const throw() {
	return "No matching price found.";
}
