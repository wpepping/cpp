#include <string>

#ifndef SCALARCONVERTERFORMATS_H__
#define SCALARCONVERTERFORMATS_H__

class ScalarConverterFormats {

public:
	ScalarConverterFormats();
	ScalarConverterFormats(char chr, int integer, double dbl, float flt);
	ScalarConverterFormats(const ScalarConverterFormats &other);
	~ScalarConverterFormats();
	ScalarConverterFormats &operator=(const ScalarConverterFormats &other);

	char getChr() const;
	int getInteger() const;
	double getDbl() const;
	float getFlt() const;

	void setChr(char chr);
	void setInteger(int integer);
	void setDbl(double dbl);
	void setFlt(float flt);

private:
	char _chr;
	int _integer;
	double _dbl;
	float _flt;
};

#endif
