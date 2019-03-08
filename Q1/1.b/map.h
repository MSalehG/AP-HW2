#ifndef MAP_H
#define MAP_H

class Map
{
public:

	Map () = default;
	Map (int N);
	~Map();

	void showMap();
	void findRoute();
	void showRoute();

	int n;
	int** obstacle; //The random number assigned to each block
	int** route; //The array which we use to display the select route with '*'
	int* list; //The array which we use to calculate the total distance by storing the height of each block which is in the select route

private:

};


#endif


















