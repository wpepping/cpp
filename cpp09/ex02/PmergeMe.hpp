#ifndef __PMERGME_H__
#define __PMERGME_H__

#include <cmath>
#include <cstddef>
#include <map>
#include <utility>
#include <vector>

typedef std::vector<int> 		intvec;
typedef std::multimap<int, int>	intmap;
typedef std::pair<int, int> 	intpair;

typedef struct s_pair {
	int high;
	int low;
	int index;
} t_pair;

class PmergeMe {
public:
	static void sort(intvec &container);

private:
	PmergeMe();
	~PmergeMe();

	static void _fillPairsAndInsertLargest(
		intvec &S,
		intmap &pairs,
		intvec &container
	);
	static void _insertSmallest(intvec &S, intmap &pairs, int *oddEnd);
	static void _insertItems(intvec &S, intmap &pairs, int *oddEnd, int group_size, size_t index);
	static void _binaryInsert(intvec &S, int item, size_t index);
};

#endif
