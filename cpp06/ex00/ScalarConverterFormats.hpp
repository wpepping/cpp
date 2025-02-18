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

	char getChar() const;
	int getInt() const;
	double getDouble() const;
	float getFloat() const;

	void setChar(char chr);
	void setInt(int integer);
	void setDouble(double dbl);
	void setFloat(float flt);

private:
	char	_chr;
	int		_integer;
	double	_dbl;
	float	_flt;
};

#endif
