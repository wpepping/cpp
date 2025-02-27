#include <algorithm>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <vector>

#ifndef __SPAN_H__
#define __SPAN_H__

class Span {
public:
	class CapacityLimitReachedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class UnableToComplyException : public std::exception {
	public:
		virtual const char* what() const throw();
	};


	Span();
	Span(unsigned int max_size);
	~Span();
	Span(const Span &src);
	Span &operator=(const Span &src);

	void addNumber(const int n);
	int shortestSpan() const;
	int longestSpan() const;
	unsigned int size() const;

	template <typename T>
	void addNumbers(typename T::iterator begin, typename T::iterator end) {
		if (std::distance(begin, end) > _max_size - _size)
			throw Span::CapacityLimitReachedException();
		while (begin != end)
			addNumber(*(begin++));
	}

private:
	unsigned int		_max_size;
	unsigned int		_size;
	std::vector<int>	_data;
};

#endif
