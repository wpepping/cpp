#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::sort(intvec &container) {
	intvec	S;
	intmap	pairs;

	_fillPairsAndInsertLargest(S, pairs, container);
	sort(S);
	S.insert(S.begin(), (*pairs.find(S[0])).second);
	_insertSmallest(S, pairs, (container.size() % 2 ? &container.back() : NULL));
}

void PmergeMe::_fillPairsAndInsertLargest(
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

void PmergeMe::_insertSmallest(intvec &S, intmap &pairs, int *oddEnd) {
	size_t	index;
	int		group_size;
	int		power;

	group_size = 2;
	power = 2;
	index = 2;
	while (index + group_size < S.size()) {
		_insertItems(S, pairs, oddEnd, group_size, index);
		index += group_size;
		group_size = std::pow(2, power) - group_size;
		power++;
	}
}

void PmergeMe::_insertItems(intvec &S, intmap &pairs, int *oddEnd, int group_size, size_t index) {
	if (index + group_size >= pairs.size()) {
		if (oddEnd) {
			_binaryInsert(S, *oddEnd, index);
			index++;
		}
		group_size = pairs.size() - index;
	}
	for (; index + group_size < pairs.size(); index++) {
		_binaryInsert(S, pairs.find(S[index])->second, index);
	}
}

void PmergeMe::_binaryInsert(intvec &S, int item, size_t index) {
	int	min = 0;
	int max = index;
	int i = (max - min) / 2;

	while (max - min > 1) {
		if (item > S[i])
			min = i;
		else
			max = i;
		i = (max - min) / 2;
	}
	if (min == 0 && item < S[0])
		S.insert(S.begin(), item);
	else
		S.insert(S.begin() + index, item);
}
