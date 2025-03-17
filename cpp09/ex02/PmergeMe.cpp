#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

 #include <iostream>
 static void printContainer(std::string message, const std::vector<int> &vec) {
 	//std::cout << message;
 	for (size_t i = 0; i < vec.size(); ++i) {
 		//std::cout << vec[i];
 		if (i < vec.size() - 1) {
			(void)message;
 			//std::cout << ' ';
		}
 	}
 	//std::cout << std::endl;
 }

std::vector<int> PmergeMe::sort(std::vector<int> &container) {
	intvec	S;
	intmap	pairs;

	printContainer("Sort input: ", container);

	if (container.size() == 1)
		return intvec(1, container[0]);
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
		//std::cout << "pair: " << container[i] << "," << container[i + 1] << std::endl;
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
	size_t	group_size;
	int		power;

	printContainer("Insert smallest - S = ", S);

	group_size = 0;
	power = 1;
	index = std::min<std::size_t>(2, S.size());
	while (index < S.size() + (oddEnd ? 1 : 0)) {
		group_size = std::pow(2, power) - group_size;
		//std::cout << "Group size: " << group_size << std::endl;
		_insertItems(S, pairs, oddEnd, group_size, index);
		index += group_size * 2;
		power++;
	}
}

void PmergeMe::_insertItems(intvec &S, intmap &pairs, int *oddEnd, size_t group_size, size_t index) {
	size_t 	upper_bound;
	size_t	last_element = std::min(index + group_size, S.size());
	intvec	elements(&S[index], &S[last_element]);

	if (index + group_size > S.size()) {
		if (oddEnd)
			_binaryInsert(S, *oddEnd, S.size() - 1);
		group_size = elements.size();
		if (group_size == 0)
			return;
	}

	//std::cout << "insert items, index=" << index << ", group_size=" << group_size << std::endl;

	upper_bound = index + group_size - 1;
	//std::cout << "upper_bound: " << upper_bound << std::endl;
	for (size_t i = 1; i <= group_size; i++) {
		printContainer("S: ", S);
		//std::cout << "Insert y" << (upper_bound-i+2) << ", x=" << elements[group_size - i] << ", y=" << pairs.find(elements[group_size - i])->second 	<< std::endl;
		_binaryInsert(S, pairs.find(elements[group_size - i])->second, upper_bound);
	}
}

void PmergeMe::_binaryInsert(intvec &S, int item, size_t upper_bound) {
	int	min = 0;
	int max = upper_bound;
	int i;

	while (min < max) {
		i = min + (max - min) / 2;
		if (item > S[i])
			min = i + 1;
		else
			max = i - 1;
	}
	S.insert(S.begin() + max + (S.size() && item > S[max] ? 1 : 0), item);
}
