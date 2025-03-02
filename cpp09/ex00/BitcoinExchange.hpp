#include <ctime>
#include <exception>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange {
public:
	class PriceNotFoundException : std::exception {
	public:
		virtual const char* what() const throw();
	};

	class ErrorReadingFileException : std::exception {
	public:
		virtual const char* what() const throw();
	};

	BitcoinExchange();
	BitcoinExchange(std::string fname);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange();
	BitcoinExchange &operator=(BitcoinExchange const &src);

	double getBitcoinPrice(const time_t &date) const
		throw(PriceNotFoundException);

private:
	std::map<time_t, double> _data;

	void _initDb(const std::string &fname) throw(ErrorReadingFileException);
	void _parseLine(std::ifstream &infile) throw(ErrorReadingFileException);
	time_t _parseDate(std::ifstream &infile) const
		throw(ErrorReadingFileException);
	double _parsePrice(std::ifstream &infile) const
		throw(ErrorReadingFileException);
	bool _expectChar(std::ifstream &infile, char c) const;
};
