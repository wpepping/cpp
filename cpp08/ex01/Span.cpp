#include "Span.hpp"

Span::Span() : _max_size(0), _size(0) { }

Span::Span(unsigned int max_size) : _max_size(max_size), _size(0) { }

Span::Span::~Span() { }

Span::Span(const Span &src) {
	_size = src._size;
	_data = src._data;
}

Span &Span::operator=(const Span &src) {
	if (&src != this) {
		_size = src._size;
		_data = src._data;
	}
	return *this;
}

void Span::addNumber(int n) throw(CapacityLimitReachedException) {
	if (_size >= _max_size)
		throw Span::CapacityLimitReachedException();
	_size++;
	_data.push_back(n);
}

int Span::shortestSpan() const throw(UnableToComplyException) {
	int min = std::numeric_limits<int>::max();

	if (_size < 2)
		throw Span::UnableToComplyException();
	for (unsigned int i = 0; i <= _size; i++) {
		for (unsigned int j = 0; j <= _size; j++) {
			if (i != j && abs(_data[i] - _data[j]) < min)
				min = abs(_data[i] - _data[j]);
		}
	}
	return min;
}

int Span::longestSpan() const throw(UnableToComplyException) {
	if (_size < 2)
		throw Span::UnableToComplyException();
	return *std::max_element(_data.begin(), _data.end())
		- *std::min_element(_data.begin(), _data.end());
}

unsigned int Span::size() const {
	return _size;
}

const char *Span::CapacityLimitReachedException::what() const throw() {
	return "Capacity Limit Reached";
}

const char *Span::UnableToComplyException::what() const throw() {
	return "Unable to comply, need at least 2 numbers";
}
