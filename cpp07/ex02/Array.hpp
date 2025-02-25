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

	Array<T>(unsigned int size) {
		_array = new T[size]();
		_size = size;
	}

	Array<T>(Array<T> &src) {
		_array = new T[src._size];
		_size = src._size;

		for (unsigned int i = 0; i < src._size; i++) {
			_array[i] = T(src._array[i]);
		}
	}

	Array<T> &operator=(const Array<T> &src) {
		if (this != &src) {
			delete[] _array;

			_array = new T[src._size];
			_size = src._size;
			for (unsigned int i = 0; i < src._size; i++) {
				_array[i] = T(src._array[i]);
			}
		}
		return *this;
	}

	~Array<T>() {
		delete[] _array;
	}

	T &operator[](unsigned int i) const throw(IndexOutOfBoundsException) {
		if (i >= _size)
			throw IndexOutOfBoundsException();
		return _array[i];
	}

	unsigned int size() const {
		return _size;
	}

private:
	unsigned int	_size;
	T				*_array;
};

#endif
