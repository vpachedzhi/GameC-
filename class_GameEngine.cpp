#include "Hero_Game.h"

// Helper function that sets all of the buttons in an array of pointers
Action** setAct()
{
	Action** act = new Action* [numberOfActs];

		act[0] = new Up;
		act[1] = new Down;
		act[2] = new Left;
		act[3] = new Right;
		act[4] = new Exit;
		act[5] = new KeyMap;
		act[6] = new SaveGame;
	
	return act;
}

// Depending on the pressed button the relevant action is chosen
void GameEngine::choseAction(char c)
{
	Action** act = setAct();

	for(int i=0; i<numberOfActs; i++)
		if(c == act[i]->symbol() )
		{
			act[i]->Act(map,hero);
		}
	
}

// Prints the map's & the hero's table
void GameEngine::Print() const
{
	system("cls");
	map.printMap();
	hero.Print();
}