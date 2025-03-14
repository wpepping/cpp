#ifndef __PMERGME_H__
#define __PMERGME_H__

#include <cmath>
#include <cstddef>
#include <map>
#include <utility>
#include <vector>

typedef intvec intvec;
typedef intmap intmap;
typedef std::pair<int, int> intpair;

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
	static void fillY(intvec &y, intvec &S, intmap &pairs, int *oddEnd);
	static void addItems(intvec &y, intvec &S, intmap &pairs, int *oddEnd, int group_size, int index);
};

#endif
