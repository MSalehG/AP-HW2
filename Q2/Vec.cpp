#include <vector>
#include "Vec.h"

void libVec::counter(int N, int& s)
{

	std::vector<int> v;
	int cnt{};

	for (int i{}; i < N; i++)
	{
		v.push_back(i);
		cnt += v[i];
	}
	s = cnt;
}

libVec::~libVec()
{

}
