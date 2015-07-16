#include "Hero_Game.h"

// Player choses new game or to load the previous one
void Choice(GameEngine &gm)
{
	cout<<" New game -> 1\n Load game -> 2\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		{
			Map m1(1);
			gm.setMap(m1);
			break;
		}
	case 2:
		{
			Map m2(0);		// Putting '0' in the Map's constructor loades the saved map
			gm.setMap(m2);
			ifstream file("Save.dat", std::ios::binary);
			Hero h1(file);
			gm.hero = h1;
			break;
		}
	default:
		cout<<"	Please restart the game and press correct number !!!\n";
		fail = true;
		isRunning = false;
		break;
	}
}

bool isRunning = true;
bool fail = false;
bool win = false;

int main()
{
	GameEngine GM;
	
	// The player chooses new game or loading saved game
	Choice(GM);

	// Setting the position of the hero
	GM.hero.setHeroPos(GM.getMap());

	if(!fail)
		GM.Print();
	
	while( isRunning )
	{
		GM.choseAction( getch() );
		GM.Print();

		if(GM.hero.getLife() <= 0)
			isRunning = false;
	}

	if(win)
		cout<<"\n\n	You win !!!\n\n";
	else
		cout<< "\n\n Game Over\n\n";

	if(fail)
		cout<<"\nSOME FILES DOES NOT EXIT,\n\tPLEASE CHECK YOUR GAME'S FOLDER\n";

	return 0;
}
