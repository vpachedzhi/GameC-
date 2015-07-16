#include "Hero_Game.h"

///
/// All members of the Hero class
///

// Setters of life & power
void Hero::setLife(float l)
{
	if( l >= 0 )
		life = l;
	else
		life = 0;
}
void Hero::setPower(float p)
{
	if( p >= 0 )
		power = p;
	else 
		power = 0;
}

// Finds where is the hero
void Hero::setHeroPos(Map &map)
{
	for(int i=0; i<map.getLines(); i++)
		for(int j=0; j<map.getColons(); j++)
			if( map.arr[i][j] == '$')
			{
				line = i;
				colon = j;
			}
}

// Prints the table of the hero
void Hero::Print() const
{
	cout<<endl;
	cout<<"_____________________"<<endl
		<<" LIFE   POWER   MANA|"<<endl
		<<setw(5)<<this->getLife()<<" "
		<<setw(7)<<this->getPower()<<" "
		<<setw(6)<<this->getMana()<<"|"
		<<"\n____________________|"<<endl;

	if( hasSword() )
		cout<<" SWOWRD ";
	if( hasHelmet() )
		cout<<" HELMET ";
	if( hasShield() )
		cout<<" SHIELD ";
}

// Saves all the information about the hero in a binary file
void Hero::SeveToFile(ofstream &file)
{
	file.write((char*)&life,sizeof(life));
	file.write((char*)&power,sizeof(power));
	file.write((char*)&mana,sizeof(mana));
	file.write((char*)&sword,sizeof(sword));
	file.write((char*)&helmet,sizeof(helmet));
	file.write((char*)&shield,sizeof(shield));

	if (!file)
		std::cerr << "Hero not saved correctly!";
	
}

// Crates new hero from a binary file
Hero::Hero(std::ifstream &file)
{
	if(file.good())
	{
		file.read((char*)&life,sizeof(float));
		file.read((char*)&power,sizeof(float));
		file.read((char*)&mana,sizeof(int));
		file.read((char*)&sword,sizeof(bool));
		file.read((char*)&helmet,sizeof(bool));
		file.read((char*)&shield,sizeof(bool));
	}
	else
	{
		isRunning = false;
		fail = true;
	}
}