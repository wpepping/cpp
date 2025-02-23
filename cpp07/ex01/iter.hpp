#include <cstddef>

#ifndef __ITER_H__
#define __ITER_H__

template<typename T>
void iter(T arr[], std::size_t size, void (*f)(T)) {
	for (size_t i = 0; i < size; i++)
		(*f)(arr[i]);
}

#endif
