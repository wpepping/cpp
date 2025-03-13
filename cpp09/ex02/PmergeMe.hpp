#ifndef __PMERGME_H__
#define __PMERGME_H__

#include <vector>
#include <unordered_map>

typedef struct s_pair {
	int high;
	int low;
	int index;
} t_pair;

class PmergeMe {
public:
	static void sort(std::vector<int> &container);

private:
	PmergeMe();
	~PmergeMe();

	static void _fillPairsAndInsertLargest(
		std::vector<int> &S,
		std::unordered_map<int, int> &pairs,
		std::vector<int> &container
	);
	static void _insertSmallest(std::vector<int> &result, std::unordered_map<int, int> &pairs);
};

#endif
