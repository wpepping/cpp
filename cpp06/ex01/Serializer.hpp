#include <stdint.h>
#include "Data.hpp"

class Serializer {

public:
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);

private:
	Serializer();
	~Serializer();
};
