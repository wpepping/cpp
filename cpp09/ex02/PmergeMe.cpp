#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::_fillPairsAndInsertLargest(
	intvec &S,
	intmap &pairs,
	intvec &container
) {
	for (int i = 0; i < container.size() - 1; i += 2) {
		if (container[i + 1] > container[i]) {
			pairs.insert(intpair(container[i + 1], container[i]));
			S.push_back(container[i + 1]);
		} else {
			pairs.insert(intpair(container[i], container[i + 1]));
			S.push_back(container[i]);
		}
	}
}

void PmergeMe::addItems(intvec &y, intvec &S, intmap &pairs, int *oddEnd, int group_size, int index) {

}

void PmergeMe::fillY(intvec &y, intvec &S, intmap &pairs, int *oddEnd) {
	int index;
	int group_size;
	int power;

	y.reserve(pairs.size() - 1 + (oddEnd? 1 : 0));
	group_size = 0;
	power = 1;
	index = 2;
	while (index + group_size < S.size()) {
		group_size = std::pow(2, power) - group_size;
		addItems(y, S, pairs, oddEnd, group_size, index);
	}
}

void PmergeMe::_insertSmallest(intvec &S, intmap &pairs, int *oddEnd) {
	(void)S;
	(void)pairs;
	intvec y;

	fillY(y, S, pairs, oddEnd);
}

void PmergeMe::sort(intvec &container) {
	intvec				S;
	intmap	pairs;

	_fillPairsAndInsertLargest(S, pairs, container);
	sort(S);
	S.insert(S.begin(), (*pairs.find(S[0])).second);
	_insertSmallest(S, pairs, (container.size() % 2 ? &container.back() : NULL));
}
