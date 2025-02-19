#include <stdint.h>
#include "Data.hpp"

#ifndef _SERIALIZER_H__
#define _SERIALIZER_H__

class Serializer {

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer();
	~Serializer();
};

#endif
