#include "Arr.h"

void libArr::counter(int N, int& s)
{

	int* arr{ new int[N] };
	int cnt{};

	for (int i{}; i < N; i++)
	{
		arr[i] = i;
		cnt += arr[i];
	}

	delete[] arr;
	s = cnt;
}

libArr::~libArr()
{

}
