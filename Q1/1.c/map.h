#ifndef MAP_H
#define MAP_H

int fact(int N); //The function to calculate the factorial of N

class Map
{
public:

	Map () = default; //Default constructor
	Map (int N);
	~Map(); //Destructor

	void showMap();
	void findRoute();
	void showRoute();

	int n, num;  //The total number of permutation of routes for reaching the bottom from the top
	int** obstacle; //The random number assigned to each block
	int** route; //The array which we use to display the select route with '*'
	int* list; //The array which we use to calculate the total distance by storing the height of each block which is in the select route
	char** alt; //The array which we use to store different permutaions and then to pass each route and calculate the distance

private:

};

#endif



















