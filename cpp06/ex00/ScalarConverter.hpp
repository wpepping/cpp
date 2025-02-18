#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include "ScalarConverterFormats.hpp"

#ifndef _SCALAR_CONVERTER_H__
#define _SCALAR_CONVERTER_H__

#define INF "inf"
#define NEGATIVE_INF "-inf"
#define NAN "nan"
#define INF_FLOAT "inff"
#define NEGATIVE_INF_FLOAT "-inff"

class ScalarConverter {

public:
	class ConversionFailedException : std::exception {
	public:
		virtual const char* what() const throw();
	};

	static void convert(std::string str);

private:
	ScalarConverter();
	~ScalarConverter();

	static bool						_isChar(std::string str);
	static bool						_isInt(std::string str);
	static bool						_isDouble(std::string str);
	static bool						_isFloat(std::string str);
	static void						_err_handl(std::string message);
	static void						_output_formats(ScalarConverterFormats *formats);
	static ScalarConverterFormats*	_readFromInt(std::string str) throw(ConversionFailedException);
	static ScalarConverterFormats*	_readFromDouble(std::string str) throw(ConversionFailedException);
	static ScalarConverterFormats*	_readFromFloat(std::string str) throw(ConversionFailedException);
	static ScalarConverterFormats*	_readFromChar(std::string str);
};

#endif
