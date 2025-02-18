#include "ScalarConverterFormats.hpp"

ScalarConverterFormats::ScalarConverterFormats()
	: _chr(0), _integer(0), _dbl(0.0), _flt(0.0f) {}

ScalarConverterFormats::ScalarConverterFormats(char chr, int integer, double dbl, float flt)
	: _chr(chr), _integer(integer), _dbl(dbl), _flt(flt) {}

ScalarConverterFormats::ScalarConverterFormats(const ScalarConverterFormats& other)
	: _chr(other._chr), _integer(other._integer), _dbl(other._dbl), _flt(other._flt) {}

ScalarConverterFormats::~ScalarConverterFormats() {}

ScalarConverterFormats& ScalarConverterFormats::operator=(const ScalarConverterFormats& other) {
	if (this != &other) {
		_chr = other._chr;
		_integer = other._integer;
		_dbl = other._dbl;
		_flt = other._flt;
	}
	return *this;
}

char ScalarConverterFormats::getChar() const {
	return _chr;
}

int ScalarConverterFormats::getInt() const {
	return _integer;
}

double ScalarConverterFormats::getDouble() const {
	return _dbl;
}

float ScalarConverterFormats::getFloat() const {
	return _flt;
}

void ScalarConverterFormats::setChar(char chr) {
	_chr = chr;
}

void ScalarConverterFormats::setInt(int integer) {
	_integer = integer;
}

void ScalarConverterFormats::setDouble(double dbl) {
	_dbl = dbl;
}

void ScalarConverterFormats::setFloat(float flt) {
	_flt = flt;
}
