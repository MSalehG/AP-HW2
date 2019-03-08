#include <iostream>
#include <cmath>
#include "map.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>

int fact(int N)
{
	if (N == 1 || N == 0)
		return 1;
	else
		return N * fact(N - 1);
}

Map::Map(int N)
{
	srand((unsigned)time(NULL)); //This command makes the random numbers generated in each run of the program different

	n = N;

	int iter{}; //index is used to show which permutation we are putting into alt

	num = fact(2 * n - 2) / fact(n - 1) / fact(n - 1);

	obstacle = new int*[n];
	route = new int*[n];
	list = new int[2 * n - 1];
	alt = new char*[num];

	for (int i{}; i < n; i++)
	{
		obstacle[i] = new int[n];
		route[i] = new int[n];

		for (int j{}; j < n; j++)
		{
			obstacle[i][j] = rand() % 101; //Filling obstacle with random numbers ranged from 0 to 100
			route[i][j] = 0;

		}
	}
	route[0][0] = 1; //Each block which is in the select route is 1 in this array and others are 0

	for (int i{}; i < 2 * n - 1; i++)
		list[i] = 0;

	for (int i{}; i < num; i++)
		alt[i] = new char[2 * (n - 1)];

	for (int i{}; i < 2 * (n - 1); i++)
	{
		if (i < n - 1)
			alt[0][i] = 'r';
		else
			alt[0][i] = 'd';
	}

	std::sort(&alt[0][0], &alt[0][2 * (n - 1)]);


	do
	{
		for (int i{}; i < 2 * (n - 1); i++)
			alt[iter][i] = alt[0][i];

		iter++;

	} while (std::next_permutation(&alt[0][0], &alt[0][2 * (n - 1)]));

}




void Map::showMap()
{
	for (int i{}; i < n; i++)
	{
		for (int j{}; j < n; j++)
		{
			std::cout << obstacle[i][j] << '\t';
		}
		std::cout << '\n';
	}
}

void Map::findRoute()
{
	int* D{ new int[num] }; //The dynamic array in which we store different distances

	int row{}, column{}, r{}, c{}, index{};

	for (int k{}; k < num; k++) //This loop calculates the distance for each possible route
	{
		D[k] = 0;
		list[0] = 0;
		row = 0;
		column = 0;

		for (int i{}; i < 2 * n - 2; i++)
		{

			if (alt[k][i] == 'd') //This if makes the route take down if it sees 'd' in alt
			{

				row = row + 1;
				list[i + 1] = row * n + column; //This comman stores the row and column of the select block in form of one number in the "list"

				r = static_cast<int>(list[i] / n); //This command calculates the row of the previous block on the route
				c = static_cast<int>(list[i] % n); //This command calculates the column of the previous block on the route
				D[k] += abs(obstacle[row][column] - obstacle[r][c]);
			}

			else if (alt[k][i] == 'r') //This if makes the route take right if it sees 'r' in alt
			{

				column = column + 1;
				list[i + 1] = row * n + column;

				r = static_cast<int>(list[i] / n);
				c = static_cast<int>(list[i] % n);
				D[k] += abs(obstacle[row][column] - obstacle[r][c]);
			}
		}
	}
	row = 0;
	column = 0;

	for (int k{ 1 }; k < num; k++) //In this loop we find the shrotest route
	{
		if (D[k] < D[index])
			index = k;

	}

	for (int i{}; i < 2 * n - 2; i++) //This for puts 1 in "route" for each block that is on the shortest distance route
	{

		if (alt[index][i] == 'd')
		{
			row = row + 1;
			route[row][column] = 1;
		}

		else if (alt[index][i] == 'r')
		{
			column = column + 1;
			route[row][column] = 1;
		}
	}

	std::cout << "\nThe distance for each route is listed below : \n";
	for (int i{}; i < num; i++)
		std::cout << i + 1 << ". " << D[i] << "\n";


	std::cout << "\n\nThe shortest distance is : " << D[index] << "\n\n";
	delete[] D;
}

void Map::showRoute()
{
	for (int i{}; i < n; i++)
	{
		for (int j{}; j < n; j++)
		{
			if (route[i][j] == 1)
				std::cout << '*' << '\t';
			else
				std::cout << ' ' << '\t';
		}
		std::cout << '\n';
	}
}



Map::~Map()
{
	for (int i{}; i < n; i++)
	{
		delete[] obstacle[i];
		delete[] route[i];
		delete[] alt[i];
	}



	delete[] obstacle;
	delete[] route;
	delete[] list;
	delete[] alt;
}



