#pragma once

enum Actions
{
	up,
	down,
	_left,
	_right,
	exiT,
	help,
	saveGame,
	numberOfActs
};

// Abstract class
class Action
{
public:
	// Returns the symbol of the key
	virtual char symbol() = 0;

	// Relevant operation over the current map & the hero
	virtual void Act(Map &m, Hero &h) = 0;

	// Returns the type
	virtual Actions getType() = 0 ;
};

// Four inheritor classes moving the hero in the four directions
class Up: public Action
{
public:
	Up() {}
	~Up() {}
	virtual char symbol() { return 'w'; }
	virtual void Act(Map &m, Hero &h);
	virtual Actions getType() { return up; } 
};

class Down: public Action
{
public:
	Down() {}
	~Down(){}
	virtual char symbol() { return 's'; }
	virtual void Act(Map &m, Hero &h);
	virtual Actions getType() { return down; } 
};

class Left: public Action
{
public:
	Left() {}
	~Left(){}
	virtual char symbol() { return 'a'; }
	virtual void Act(Map &m, Hero &h);
	virtual Actions getType() { return _left; } 
};

class Right: public Action
{
public:
	Right() {}
	~Right(){}
	virtual char symbol() { return 'd'; }
	virtual void Act(Map &m, Hero &h);
	virtual Actions getType() { return _right; } 
};

// Inheritor class Exit
 class Exit: public Action
{
public:
	virtual char symbol() { return 'q';}
	virtual void Act(Map &m, Hero &h) { isRunning = false; }
	virtual Actions getType() {return exiT;}

};

// Inheritor class Help menu
 class KeyMap: public Action
{
public:
	virtual char symbol() {return 'h';}
	virtual void Act(Map &m, Hero &h);
	virtual Actions getType() {return help;}
};

// Save Game
 class SaveGame: public Action
 {
 public:
	 virtual char symbol() { return 'f'; }
	 virtual void Act(Map &m, Hero &h);
	 virtual Actions getType() { return saveGame; }
 };