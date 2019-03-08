#include <iostream>
#include <cmath>
#include <vector>
#include "Vec.h"
#include "Arr.h"
#include <ctime>

template <typename T>
long double runTime(T list, int N, int sum);


int main()
{
	libVec vec{};
	libArr arr{};

	long double time;
	int N{ 10000000 }, s{};

	std::cout << CLOCKS_PER_SEC << " clocks per second" << std::endl;

	time = runTime (arr, N, s);

	std::cout << "The time needed to execute counter in libArr for N = " << N 
		<< " is : " << (time / CLOCKS_PER_SEC * 1000) << " miliseconds" << std::endl;

	time = runTime (vec, N, s);

	std::cout << "The time needed to execute counter in libVec for N = " << N 
		<< " is : " << (time / CLOCKS_PER_SEC * 1000) << " miliseconds" << "\n\n";


}
	
template <typename T>
long double runTime(T list, int N, int sum)
{

	long double t{ static_cast<long double>(std::clock()) };

	list.counter(N, sum);

	t = static_cast<long double>(std::clock()) - t;
	return t;

}

