#include "ScalarConverter.hpp"
#include "ScalarConverterFormats.hpp"

ScalarConverter::ScalarConverter() { }
ScalarConverter::~ScalarConverter() { }

void ScalarConverter::convert(std::string str) {
	ScalarConverterFormats* formats;

	if (_isInt(str))
		formats = _readFromInt(str);
	else if (_isDouble(str))
		formats = _readFromDouble(str);
	else if (_isFloat(str))
		formats = _readFromFloat(str);
	else if (_isChar(str))
		formats = _readFromChar(str);
	else
		_err_handl("Conversion error");

	_output_formats(formats);
	delete formats;
}

bool ScalarConverter::_isChar(std::string str) {
	return (str.length() == 1 && isprint(str[0]));
}

bool ScalarConverter::_isInt(std::string str) {
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::_isDouble(std::string str) {
	size_t dotpos;

	if (str == INF || str == NEGATIVE_INF || str == NAN)
		return true;
	dotpos = str.find_first_of('.');
	if (dotpos == std::string::npos || !_isInt(str.substr(0, dotpos + 1)) || !_isInt(str.substr(dotpos + 1)))
		return false;
	return true;
}

bool ScalarConverter::_isFloat(std::string str) {
	size_t dotpos;
	size_t strlen;

	if (str == INF_FLOAT || str == NEGATIVE_INF_FLOAT)
		return true;
	strlen = str.length();
	if (str[strlen - 1] != 'f')
		return false;
	dotpos = str.find_first_of('.');
	if (dotpos == std::string::npos)
	{
		if (!_isInt(str.substr(0, strlen - 1)))
			return false;
		return true;
	}
	if (!_isInt(str.substr(0, dotpos + 1)) || !_isInt(str.substr(dotpos + 1, strlen - dotpos - 1)))
		return false;
	return true;
}

ScalarConverterFormats* ScalarConverter::_readFromInt(std::string str) {
}

ScalarConverterFormats* ScalarConverter::_readFromDouble(std::string str) {
}

ScalarConverterFormats* ScalarConverter::_readFromFloat(std::string str) {
}

ScalarConverterFormats* ScalarConverter::_readFromChar(std::string str) {
}
