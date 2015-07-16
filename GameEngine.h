#pragma once

class GameEngine
{
	// Current map
	Map map;
	
public:
	
	Hero hero;

	// Constructor & destructor
	GameEngine() {}
	~GameEngine(){}
	
	// Setter & getter for the map
	void setMap(Map &m) { map = m; }
	Map& getMap() { return map; }

	// Depending on the pressed button the relevant action is chosen
	void choseAction(char c);

	// Prints the map's & the hero's table
	void Print() const;

};