#include "ScalarConverter.hpp"
#include "ScalarConverterFormats.hpp"

bool _isChar(std::string str) {
	return (str.length() == 1 && isprint(str[0]));
}

bool _isInt(std::string str) {
	size_t	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	for (; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return (i > 0);
}

bool _isDouble(std::string str) {
	size_t dotpos;
	size_t strlen;

	if (str == INF || str == NEGATIVE_INF || str == NAN)
		return true;
	strlen = str.length();
	dotpos = str.find_first_of('.');
	if (strlen == 0 || dotpos == std::string::npos || !_isInt(str.substr(0, dotpos))
		|| (dotpos != strlen - 1 && !_isInt(str.substr(dotpos + 1))))
		return false;
	return true;
}

bool _isFloat(std::string str) {
	std::string substr;
	size_t		strlen;

	strlen = str.length();
	if (strlen < 2 || str[strlen - 1] != 'f')
		return false;
	substr = str.substr(0, strlen - 1);
	return (_isInt(substr) || _isDouble(substr));
}

ScalarConverterFormats* _readFromInt(std::string str)
	throw(ScalarConverter::ConversionFailedException) {
	const char				*c_str;
	char					*str_end;
	long					l;
	ScalarConverterFormats 	*formats;

	c_str = str.c_str();
	l = strtol(c_str, &str_end, 10);
	if (c_str == str_end || l < std::numeric_limits<int>::min()
		|| l > std::numeric_limits<int>::max())
		throw ScalarConverter::ConversionFailedException();
	formats = new ScalarConverterFormats();
	formats->setInt(l);
	formats->setChar(static_cast<char>(l));
	formats->setDouble(static_cast<double>(l));
	formats->setFloat(static_cast<float>(l));
	return formats;
}

ScalarConverterFormats* _readFromDouble(std::string str)
	throw(ScalarConverter::ConversionFailedException) {
	const char				*c_str;
	char					*str_end;
	double					d;
	ScalarConverterFormats 	*formats;

	c_str = str.c_str();
	d = strtod(c_str, &str_end);
	if (c_str == str_end)
		throw ScalarConverter::ConversionFailedException();
	formats = new ScalarConverterFormats();
	formats->setDouble(d);
	formats->setChar(static_cast<char>(d));
	formats->setInt(static_cast<double>(d));
	formats->setFloat(static_cast<float>(d));
	return formats;
}

ScalarConverterFormats* _readFromFloat(std::string str)
	throw(ScalarConverter::ConversionFailedException) {
	const char				*c_str;
	char					*str_end;
	float					f;
	ScalarConverterFormats 	*formats;

	c_str = str.c_str();
	f = strtof(c_str, &str_end);
	if (c_str == str_end)
		throw ScalarConverter::ConversionFailedException();
	formats = new ScalarConverterFormats();
	formats->setFloat(f);
	formats->setChar(static_cast<char>(f));
	formats->setInt(static_cast<double>(f));
	formats->setDouble(static_cast<float>(f));
	return formats;
}

ScalarConverterFormats* _readFromChar(std::string str) {
	ScalarConverterFormats 	*formats;

	formats = new ScalarConverterFormats();
	formats->setChar(str[0]);
	formats->setInt(static_cast<int>(str[0]));
	formats->setDouble(static_cast<double>(str[0]));
	formats->setFloat(static_cast<float>(str[0]));
	return formats;
}

void _output_formats(ScalarConverterFormats& formats) {
	long 		l;
	std::string	whole_nr_decimal = (formats.getFloat() == formats.getInt()?".0":"");

	l = static_cast<long>(formats.getDouble());
	if (l < std::numeric_limits<char>::min() || l > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (isprint(formats.getChar()))
		std::cout << "char: '" << formats.getChar() << "'" << std::endl;
	else
		std::cout << "char: not printable"  << std::endl;
	if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << formats.getInt() << std::endl;
	std::cout << "float: " << formats.getFloat() << whole_nr_decimal << 'f' << std::endl;
	std::cout << "double: " << formats.getDouble() << whole_nr_decimal << std::endl;
}

void _err_handl(std::string message) {
	std::cout << message << std::endl;
}

void ScalarConverter::convert(std::string str) {
	ScalarConverterFormats* formats;

	try {
		if (_isInt(str))
			formats = _readFromInt(str);
		else if (_isDouble(str))
			formats = _readFromDouble(str);
		else if (_isFloat(str))
			formats = _readFromFloat(str);
		else if (_isChar(str))
			formats = _readFromChar(str);
		else {
			_err_handl("Conversion error");
			return;
		}
	} catch (ConversionFailedException &e) {
		_err_handl(e.what());
		return;
	}

	_output_formats(*formats);
	delete formats;
}

const char* ScalarConverter::ConversionFailedException::what() const throw() {
	return ("Conversion failed");
}

ScalarConverter::ScalarConverter() { }
ScalarConverter::~ScalarConverter() { }
