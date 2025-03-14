#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

#include <iostream>
static void printContainer(const std::vector<int> &vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << ' ';
	}
}

std::vector<int> PmergeMe::sort(std::vector<int> &container) {
	intvec	S;
	intmap	pairs;

	std::cout << "Sort input: ";
	printContainer(container);
	std::cout << std::endl;

	_fillPairsAndInsertLargest(S, pairs, container);
	if (pairs.size() > 1)
		S = sort(S);
	S.insert(S.begin(), (*pairs.find(S[0])).second);
	_insertSmallest(S, pairs, (container.size() % 2 ? &container.back() : NULL));

	std::cout << "Sort output: ";
	printContainer(S);
	std::cout << std::endl;

	return S;
}

void PmergeMe::_fillPairsAndInsertLargest(
	intvec &S,
	intmap &pairs,
	intvec &container
) {
	for (size_t i = 0; i < container.size() - 1; i += 2) {
		std::cout << "pair: " << container[i] << "," << container[i + 1] << std::endl;
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

	std::cout << "Insert smallest - S = ";
	printContainer(S);
	std::cout << std::endl;

	group_size = 0;
	power = 1;
	index = 2;
	while (index < S.size()) {
		group_size = std::pow(2, power) - group_size;
		std::cout << "Group size: " << group_size << std::endl;
		_insertItems(S, pairs, oddEnd, group_size, index);
		index += group_size * 2;
		power++;
	}
}

void PmergeMe::_insertItems(intvec &S, intmap &pairs, int *oddEnd, int group_size, size_t index) {
	if (index + group_size >= S.size()) {
		if (oddEnd) {
			_binaryInsert(S, *oddEnd, index);
			index++;
		}
		group_size = S.size() - index;
	}
	std::cout << "insert items, index=" << index << ", group_size=" << group_size << std::endl;
	for (int i = 1; index + group_size - i >= index; i++) {
		std::cout << "Insert y" << (index+group_size-i-i+2) << ", x=" << S[index + group_size - i] << ", y=" << pairs.find(S[index + group_size - i])->second 	<< std::endl;
		_binaryInsert(S, pairs.find(S[index + group_size - i])->second, index);
		index++;
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
		i = min + (max - min) / 2;
	}
	if (min == 0) {
		if (item < S[0])
			S.insert(S.begin(), item);
		else
			S.insert(S.begin() + 1, item);
	}
	else
		S.insert(S.begin() + max, item);
}
