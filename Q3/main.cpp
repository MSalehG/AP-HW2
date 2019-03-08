#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include "func.h"

int main()
{
	std::string input{ "\0" };
	
	std::ifstream in{ "db.txt" }; //This variable is for reading from the file
	std::ofstream out{ "dbnew.txt" }; //This variable is writing on the file

	std::vector <std::string> date_count; //This varibale has all the different dates
	std::vector<std::vector<std::string>> pr_count, cu_count; //These variables are sorted by date in their rows and have all the different IDs in the column so their size is what we want

	int num{ 1 }, len{}, c1{ 10 }, c2{ 16 }, c3{ 21 }, row{}; //Num is for the number of different entries in the old db, len is for the length of one entry and c1 to c3 designate at which point in an entry each info ends

	std::getline(in, input, '\0');

	int inp_length{ static_cast<int>(input.length()) };

	for (int i{}; i < inp_length; i++)
	{
		if (input[i] == '\n')
			num++;
		if (input[i] == '\n' && len == 0)
			len = i - 1;
	}

	database(input, row, c1, c2, c3, len, num, pr_count,cu_count, date_count);

	for (size_t i{}; i < date_count.size(); i++) //With this loop we write the new db in the file
	{
		out << "[" << date_count[i] << "] " << std::to_string(pr_count[i].size())
			<< " " << std::to_string(cu_count[i].size()) << '\n';
	}
	out << '\0';

}


