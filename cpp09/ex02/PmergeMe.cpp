#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::_fillPairsAndInsertLargest(
	std::vector<int> &S,
	std::unordered_map<int, int> &pairs,
	std::vector<int> &container
) {
	for (int i = 0; i < container.size() - 1; i += 2) {
		if (container[i + 1] > container[i]) {
			pairs[container[i + 1]] = container[i];
			S.push_back(container[i + 1]);
		} else {
			pairs[container[i]] = container[i + 1];
			S.push_back(container[i]);
		}
	}
}

void PmergeMe::_insertSmallest(std::vector<int> &S, std::unordered_map<int, int> &pairs) {
	(void)S;
	(void)pairs;
	/*
	    The sizes of groups are: 2, 2, 6, 10, 22, 42
		Order the uninserted elements by their groups (smaller indexes to larger indexes),
		but within each group order them from larger indexes to smaller indexes.

		First group (size 2) = y3, y4, ordered larger to smaller = y4, y3
		Second group (size 2) = y5, y6, ordered larger to smaller = y6, y5
		First group (size 6) = y7-y12, ordered larger to smaller =  y12 , y11 , y10 , y9 , y8 , y7
		etc.

		Thus, the ordering becomes

		y4 , y3 , y6 , y5 , y12 , y11 , y10 , y9 , y8 , y7 , y22 , y21 ...

		Use this ordering to insert the elements y_i. For each element y_i, use a binary search
		from the start of S up to but not including x_i to determine where to insert y_i

		Handle odd n by adding the unpaired element as y_(max+1) (obv S.size())
	*/
}

void PmergeMe::sort(std::vector<int> &container) {
	std::vector<int>				S;
	std::unordered_map<int, int>	pairs;

	_fillPairsAndInsertLargest(S, pairs, container);
	sort(S);
	S.insert(S.begin(), pairs[S[0]]);
	_insertSmallest(S, pairs);
}
