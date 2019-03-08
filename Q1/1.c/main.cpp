#include <iostream>
#include "map.h"



int main()
{
	int N;
	std::cout << "Please enter the dimension of the map : " << '\n';
	std::cin >> N;
	Map m1{ N };
	m1.showMap();
	m1.findRoute();
	m1.showRoute();
}

