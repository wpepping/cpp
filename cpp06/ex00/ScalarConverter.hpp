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
};

#endif
