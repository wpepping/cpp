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

	class ErrorReadingFile : std::exception {
	public:
		virtual const char* what() const throw();
	};

	BitcoinExchange();
	BitcoinExchange(std::string fname);
	BitcoinExchange(BitcoinExchange &src);
	~BitcoinExchange();
	BitcoinExchange &operator=(BitcoinExchange &src) const;

	const double getBitcoinPrice(const std::string &date) const;

private:
	std::map<time_t, double> _data;
	void _initDb(const std::string &fname);
	bool _storePrice(const std::string &line);
};
