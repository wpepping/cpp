#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::VectorSort::VectorSort() {}
PmergeMe::VectorSort::~VectorSort() {}
PmergeMe::ListSort::ListSort() {}
PmergeMe::ListSort::~ListSort() {}

std::vector<int> PmergeMe::VectorSort::sort(std::vector<int> &container) {
	intvec	S;
	intmap	pairs;

	if (container.size() == 1)
		return intvec(1, container[0]);
	_fillPairsAndInsertLargest(S, pairs, container);
	if (pairs.size() > 1)
		S = sort(S);
	if (pairs.size() > 0)
		S.insert(S.begin(), (*pairs.find(S[0])).second);
	_insertSmallest(S, pairs, (container.size() % 2 ? &container.back() : NULL));

	return S;
}

void PmergeMe::VectorSort::_fillPairsAndInsertLargest(
	intvec &S,
	intmap &pairs,
	intvec &container
) {
	for (size_t i = 0; i < container.size() - 1; i += 2) {
		if (container[i + 1] > container[i]) {
			pairs.insert(intpair(container[i + 1], container[i]));
			S.push_back(container[i + 1]);
		} else {
			pairs.insert(intpair(container[i], container[i + 1]));
			S.push_back(container[i]);
		}
	}
}

void PmergeMe::VectorSort::_insertSmallest(intvec &S, intmap &pairs, int *oddEnd) {
	size_t	index;
	size_t	groupSize;
	int		power;

	groupSize = 0;
	power = 1;
	index = std::min<std::size_t>(2, S.size());
	while (index < S.size() + (oddEnd ? 1 : 0)) {
		groupSize = std::pow(2, power) - groupSize;
		_insertItems(S, pairs, oddEnd, groupSize, index);
		index += groupSize * 2;
		power++;
	}
}

void PmergeMe::VectorSort::_insertItems(intvec &S, intmap &pairs, int *oddEnd, size_t groupSize, size_t index) {
	size_t 	upperBound = 0;
	size_t	last_element = std::min(index + groupSize, S.size());
	intvec	elements(&S[index], &S[last_element]);

	if (index + groupSize > S.size()) {
		if (oddEnd) {
			_binaryInsert(S, *oddEnd, S.size());
			upperBound = 1;
		}
		groupSize = elements.size();
		if (groupSize == 0)
			return;
	}

	upperBound += index + groupSize - 1;
	for (size_t i = 1; i <= groupSize; i++) {
		_binaryInsert(S, pairs.find(elements[groupSize - i])->second, upperBound);
	}
}

void PmergeMe::VectorSort::_binaryInsert(intvec &S, int item, size_t upperBound) {
	int	min = 0;
	int max = upperBound;
	int i;

	while (min < max) {
		i = min + (max - min) / 2;
		if (item > S[i])
			min = i + 1;
		else
			max = i;
	}
	S.insert(S.begin() + max, item);
}

std::list<int> PmergeMe::ListSort::sort(std::list<int> &container) {
	intlist	S;
	intmap	pairs;

	if (container.size() == 1)
		return intlist(1, container.front());
	_fillPairsAndInsertLargest(S, pairs, container);
	if (pairs.size() > 1)
		S = sort(S);
	if (pairs.size() > 0)
		S.insert(S.begin(), (*pairs.find(S.front())).second);
	_insertSmallest(S, pairs, (container.size() % 2 ? &container.back() : NULL));
	return S;
}

void PmergeMe::ListSort::_fillPairsAndInsertLargest(
	intlist	&S,
	intmap	&pairs,
	intlist	&container
) {
	intlist::iterator curr = container.begin();
	intlist::iterator next = curr;
	while (curr != container.end()) {
		++next;

		if (next == container.end())
			break;

		if (*next > *curr) {
			pairs.insert(intpair(*next, *curr));
			S.push_back(*next);
		} else {
			pairs.insert(intpair(*curr, *next));
			S.push_back(*curr);
		}

		++next;
		curr = next;
	}
}

void PmergeMe::ListSort::_insertSmallest(intlist &S, intmap &pairs, int *oddEnd) {
	size_t	index;
	size_t	groupSize;
	int		power;

	groupSize = 0;
	power = 1;
	index = std::min<std::size_t>(2, S.size());
	while (index < S.size() + (oddEnd ? 1 : 0)) {
		groupSize = std::pow(2, power) - groupSize;
		_insertItems(S, pairs, oddEnd, groupSize, index);
		index += groupSize * 2;
		power++;
	}
}

void PmergeMe::ListSort::_insertItems(intlist &S, intmap &pairs, int *oddEnd, size_t groupSize, size_t index) {
	size_t				upperBound = 0;
	size_t				last_element = std::min(index + groupSize, S.size());
	intlist::iterator	start = S.begin();
	intlist::iterator	end = S.begin();

	advance(start, index);
	advance(end, last_element);

	intvec	elements(start, end);

	if (index + groupSize > S.size()) {
		if (oddEnd) {
			_binaryInsert(S, *oddEnd, S.size());
			upperBound = 1;
		}
		groupSize = elements.size();
		if (groupSize == 0)
			return;
	}

	upperBound += index + groupSize - 1;
	for (size_t i = 1; i <= groupSize; i++) {
		_binaryInsert(S, pairs.find(elements[groupSize - i])->second, upperBound);
	}
}

void PmergeMe::ListSort::_binaryInsert(intlist &S, int item, size_t upperBound) {
	int					min = 0;
	int					max = upperBound;
	int					i;
	intlist::iterator	it;

	while (min < max) {
		i = min + (max - min) / 2;
		it = S.begin();
		advance(it, i);
		if (item > *it)
			min = i + 1;
		else
			max = i;
	}
	it = S.begin();
	advance(it, max);
	S.insert(it, item);
}
