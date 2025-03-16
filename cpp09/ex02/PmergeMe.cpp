#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

#include <iostream>
static void printContainer(std::string message, const std::vector<int> &vec) {
	std::cout << message;
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << ' ';
	}
	std::cout << std::endl;
}

std::vector<int> PmergeMe::sort(std::vector<int> &container) {
	intvec	S;
	intmap	pairs;

	printContainer("Sort input: ", container);

	_fillPairsAndInsertLargest(S, pairs, container);
	if (pairs.size() > 1)
		S = sort(S);
	if (pairs.size() > 0)
		S.insert(S.begin(), (*pairs.find(S[0])).second);
	_insertSmallest(S, pairs, (container.size() % 2 ? &container.back() : NULL));

	printContainer("Sort output: ", S);

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

	printContainer("Insert smallest - S = ", S);

	group_size = 0;
	power = 1;
	index = std::min<std::size_t>(2, S.size());
	while (index < S.size() + (oddEnd ? 1 : 0)) {
		group_size = std::pow(2, power) - group_size;
		std::cout << "Group size: " << group_size << std::endl;
		_insertItems(S, pairs, oddEnd, group_size, index);
		index += group_size * 2;
		power++;
	}
}

void PmergeMe::_insertItems(intvec &S, intmap &pairs, int *oddEnd, int group_size, size_t index) {
	int x_index;

	if (index + group_size > S.size()) {
		if (oddEnd)
			_binaryInsert(S, *oddEnd, index++);
		group_size = S.size() - index;
	}
	std::cout << "insert items, index=" << index << ", group_size=" << group_size << std::endl;
	for (int i = 1; index + group_size - i >= index; i++) {
		x_index = index + group_size - i;
		printContainer("S: ", S);
		std::cout << "Insert y" << (x_index-i+2) << ", x=" << S[x_index] << ", y=" << pairs.find(S[x_index])->second 	<< std::endl;
		_binaryInsert(S, pairs.find(S[x_index])->second, x_index);
		index++;
	}
}

void PmergeMe::_binaryInsert(intvec &S, int item, size_t x_index) {
	int	min = 0;
	int max = x_index;
	int i = (max - min) / 2;

	while (max - min > 1) {
		if (item > S[i])
			min = i;
		else
			max = i;
		i = min + (max - min) / 2;
	}
	if (min == 0)
		S.insert(S.begin() + (!S.size() || item < S[0] ? 0 : 1), item);
	else
		S.insert(S.begin() + max, item);
}
