#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "func.h"

void database(std::string inp, int& r, int C1, int C2, int C3, int length, int number,
	std::vector<std::vector<std::string>>& pr_book, std::vector<std::vector<std::string>>& cu_book,
	std::vector<std::string>& datebook)
{

	int iter{}; //This variable is used later when extracting different product and customer IDs
	std::vector<int> date_counter{ 1 }; //This variable stores the number entries for each date
	std::vector <std::string> Date, pr, cu; //These variable store each info in one block of vector

	for (int j{}; j < number; j++) //In this loop we extract the info
	{
		Date.push_back("\0");
		pr.push_back("\0");
		cu.push_back("\0");

		for (int k{ 1 }; k <= length; k++)
		{
			if (k >= 1 && k <= C1)
				Date[j] += inp[j*(length + 2) + k];
			else if (k >= C2 + 3 && k < C2 + 6)
				pr[j] += inp[j*(length + 2) + k];
			else if (k >= length - 3)
				cu[j] += inp[j*(length + 2) + k];


		}
	}
	
	datebook.push_back(Date[0]);

	for (int i{ 1 }; i < number; i++) //In this loop we extract the number of entires for each date
	{
		if (Date[i] == Date[i - 1])
			date_counter[iter]++;
		else
		{
			date_counter.push_back(1);
			datebook.push_back(Date[i]);
			iter++;
		}
	}
	iter = 0;

	r = static_cast<int>(date_counter.size()); //This variable has the total number of different dates
	int slope{}; //This variable is used to move forward in the entries in respect to "i"

	for (int i{}; i < r; i++)
	{
		pr_book.push_back(std::vector<std::string>()); //Creating different row for the new date
		cu_book.push_back(std::vector<std::string>());

		if (i == 0)
			slope = 0;
		else
			slope = slope + date_counter[i - 1];

		for (int j{}; j < date_counter[i]; j++)
		{
			if (j == 0)
			{
				pr_book[i].push_back(pr[slope + j]);
				cu_book[i].push_back(cu[slope + j]);
			}

			else
			{
				while (iter < static_cast<int>(pr_book[i].size())) //This loop extracts new product IDs
				{
					if (pr[slope + j] == pr_book[i][iter])
						break;
					else if (pr[slope + j] != pr_book[i][iter] && iter == static_cast<int>(pr_book[i].size()) - 1)
					{
						pr_book[i].push_back(pr[slope + j]);
						break;
					}
					iter++;
				}
				iter = 0;

				while (iter < static_cast<int>(cu_book[i].size())) //This loop extracts new customer IDs
				{
					if (cu[slope + j] == cu_book[i][iter])
						break;
					else if (cu[slope + j] != cu_book[i][iter] && iter == static_cast<int>(cu_book[i].size()) - 1)
					{
						cu_book[i].push_back(cu[slope + j]);
						break;
					}
					iter++;
				}
				iter = 0;
			}
		}
	}

}

