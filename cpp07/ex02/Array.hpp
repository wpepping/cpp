#include <cstddef>
#include <exception>

#ifndef __ARRAY_H__
#define __ARRAY_H__

template<typename T>
class Array {

public:
	class IndexOutOfBoundsException : std::exception {
		public:
			virtual const char* what() const throw() {
				return "Index out of bounds";
			}
	};

	Array<T>() {
		_array = new T[0];
		_size = 0;
	}

	Array<T>(size_t size) {
		_array = new T[size]();
		_size = size;
	}

	Array<T>(Array<T> &src) {
		_array = new T[src._size];
		_size = src._size;

		for (size_t i = 0; i < src._size; i++) {
			_array[i] = T(src._array[i]);
		}
	}

	Array<T> &operator=(const Array<T> &src) {
		if (this != &src) {
			delete[] _array;

			_array = new T[src._size];
			_size = src._size;
			for (size_t i = 0; i < src._size; i++) {
				_array[i] = T(src._array[i]);
			}
		}
		return *this;
	}

	~Array<T>() {
		delete[] _array;
	}

	T &operator[](size_t i) throw(IndexOutOfBoundsException) {
		if (i >= _size)
			throw IndexOutOfBoundsException();
		return _array[i];
	}

private:
	size_t	_size;
	T		*_array;
};

#endif
