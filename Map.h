#pragma once

class Map
{
	int lines, colons, level;

	// Allocates the necessary number of symbols
	void allocate(int l,int c);

public:
	char** arr;

	// Default constructor
	Map();

	// Constructor for current level
	Map(int);

	// Destructor
	~Map();

	// Deletes the map
	void clear();

	Map& operator= (const Map&);

	// Prints only the map table
	void printMap() const;

	// If the map does not exist,the function stops the game
	void failed();

	int getLines() const { return lines; }
	int getColons()const { return colons;}
	int getLevel() const { return level; }

	// Saves the map into a .txt file
	void SaveMap() const;

};