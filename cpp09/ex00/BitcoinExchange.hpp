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

	class Utils {
	public:
		static time_t parseDate(std::ifstream &infile)
			throw(ErrorReadingFileException);
		static double parsePrice(std::ifstream &infile)
			throw(ErrorReadingFileException);
		static bool expectChar(std::ifstream &infile, char c);

	private:
		Utils();
		~Utils();

		static time_t _getDate(int year, int month, int day);

		template <typename T>
		static bool _between(T nr, T min, T max) {
			return (nr >= min && nr <= max);
		}
	};

	BitcoinExchange();
	BitcoinExchange(std::string fname);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange();
	BitcoinExchange &operator=(BitcoinExchange const &src);
	double getBitcoinPrice(const time_t &date) const
		throw(PriceNotFoundException);
	int size() const;

private:
	std::map<time_t, double> _data;

	void _initDb(const std::string &fname) throw(ErrorReadingFileException);
	void _parseLine(std::ifstream &infile) throw(ErrorReadingFileException);
};
