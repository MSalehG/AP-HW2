#include <iostream>
#include <cmath>
#include "map.h"
#include <stdlib.h>
#include <time.h>



Map::Map (int N)
{
	srand((unsigned)time(NULL)); //This command makes the random numbers generated in each run of the program different

	n = N;

	obstacle = new int*[n];
	route = new int*[n];
	list = new int[2 * n - 1];

	for (int i{}; i < n; i++)
	{
		obstacle[i] = new int[n];
		route[i] = new int[n];
	}

	for (int i{}; i < n; i++)
	{
		for (int j{}; j < n; j++)
		{
			obstacle[i][j] = rand() % 101; //Filling obstacle with random numbers ranged from 0 to 100
			route[i][j] = 0;

		}
	}
	route[0][0] = 1; //Each block which is in the select route is 1 in this array and others are 0

	for (int i{}; i < 2 * n - 1; i++)
		list[i] = 0;


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
	int D{}, row{}, column{}, r{}, c{}, d1{}, d2{}; //D stores the distance and d1 and d2 store the differnce between the current block and the adjacent blocks

	for (int i{}; i < 2 * n - 2; i++)
	{

		if ((row < n -1) && (column < n - 1))
		{
			d1 = abs(obstacle[row][column] - obstacle[row + 1][column]); //The distance between the current block and the block below
			d2 = abs(obstacle[row][column] - obstacle[row][column + 1]); //The distance between the current block and the right block
			if (d2 - d1 >= 0)
			{
				row = row + 1;
				route[row][column] = 1;
				list[i + 1] = row * n + column; //This comman stores the row and column of the select block in form of one number in the "list"

				r = static_cast<int>(list[i] / n); //This command calculates the row of the previous block on the route
				c = static_cast<int>(list[i] % n); //This command calculates the column of the previous block on the route
				D += abs(obstacle[row][column] - obstacle[r][c]);

			}
			else
			{
				column = column + 1;
				route[row][column] = 1;
				list[i + 1] = row * n + column;

				r = static_cast<int>(list[i] / n);
				c = static_cast<int>(list[i] % n);
				D += abs(obstacle[row][column] - obstacle[r][c]);
			}
		}

		else if (row == n - 1 && !(column == n - 1)) //moving straight right if we have already reached the bottom row
		{
			column = column + 1;
			route[row][column] = 1;
			list[i + 1] = row * n + column;

			r = static_cast<int>(list[i] / n);
			c = static_cast<int>(list[i] % n);
			D += abs(obstacle[row][column] - obstacle[r][c]);
		}

		else if (column == n - 1 && !(row == n - 1)) //moving straight down if we have already reached the rightmost column
		{
			row = row + 1;
			route[row][column] = 1;
			list[i + 1] = row * n + column;

			r = static_cast<int>(list[i] / n);
			c = static_cast<int>(list[i] % n);
			D += abs(obstacle[row][column] - obstacle[r][c]);
		}

	}

	std::cout << "The Distance is : " << D << '\n';
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
	}
	delete[] obstacle;
	delete[] route;
	delete[] list;
}



