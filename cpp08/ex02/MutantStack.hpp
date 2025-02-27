#include <stack>

#ifndef __MUTANT_STACK_H__
#define __MUTANT_STACK_H__

template<typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

	MutantStack<T>() : std::stack<T>() { }

	~MutantStack<T>() { }

	MutantStack<T>(const MutantStack<T> &src) : std::stack<T>(src) { }

	MutantStack<T> &operator=(const MutantStack<T> &src) {
		if (this != &src)
			std::stack<T>::operator=(src);
		return *this;
	}

	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}

	reverse_iterator rbegin() {
		return this->c.rbegin();
	}

	reverse_iterator rend() {
		return this->c.rend();
	}

	const_iterator begin() const {
		return this->c.begin();
	}

	const_iterator end() const {
		return this->c.end();
	}

	const_reverse_iterator rbegin() const {
		return this->c.begin();
	}

	const_reverse_iterator rend() const {
		return this->c.end();
	}
};

#endif
