#include "Hero_Game.h"
//
// All members of the Map class
//

// Default constructor
Map::Map()
{
	arr = NULL;
}

// Destructor
Map::~Map()
{
	clear();
}

// Constructor for current level
Map::Map(int l)
{
	char mapName[9] = "map0.txt";
	if( l > 0 && l < 4)
	{
		this->level = l;
		mapName[3] = level + '0';

		ifstream file;
		file.open(mapName,ios::in);
		if(file.good())
		{
			file >> lines >> colons;
			file.ignore();
			allocate(lines,colons);
			int i = 0;
			while(file.good())
				{
					file.getline(arr[i],colons+1,'\n');
					i++;
				}
		}
		else
		{
			this->failed();
		}
		file.close();
	}
	// Loads the saved map if the level is incorect
	else 
	{
		ifstream file;
		file.open("SaveMap.txt" ,ios::in);
		int l,c;
		if(file.good())
		{
			file >> l >> c >> level;
			lines = l;
			colons = c;
			file.ignore();
			allocate(lines,colons);
			int i = 0;
			while(file.good())
				{
					file.getline(arr[i],colons+1,'\n');
					i++;
				}
		}
		else
		{
			this->failed();
		}
		file.close();
	}
}

// If the map does not exist,the function stops the game
void Map::failed()
{
	isRunning = false;
	fail = true;
	level = 0;
	lines = 0;
	colons = 0;
	allocate(0,0);
}

// Deletes the map
void Map::clear()
{
	if(arr != NULL)
	{
		for(int i=0; i<lines; i++)
			delete[] arr[i];

		delete[] arr;
		arr = NULL;
	}
}

// Allocates the necessary number of symbols
void Map::allocate(int l,int c)
{
	arr = new char* [l];
	for(int i=0; i<l ;i++)
		arr[i] = new char [c+1];

}

// Prints only the map
void Map::printMap() const
{
	for(int i=0;i<lines; i++)
		{
			cout<<arr[i];
			cout<<endl;
		}
}

Map& Map::operator=(const Map& m)
{
	if(&m != this)
	{
		for(int i=0; i<lines; i++)
			delete[] arr[i];
		delete arr;

		lines = m.lines;
		colons = m.colons;
		level = m.level;
		allocate(lines,colons);
		
		for(int i=0; i<lines; i++)
			strcpy(this->arr[i], m.arr[i]);
	}
	return *this;
}

// Saves the map into a .txt file
void Map::SaveMap()const
{
	ofstream file;
	file.open("SaveMap.txt", ios::out, ios::trunc);
	if(file.good() )
	{
		file<<lines<<" "<<colons<<" "<<level<<"\n";
		for(int i=0; i<lines; i++)
		{
			file<<arr[i];
			if( i < lines - 1)
				file<<"\n";
		}
	}
	file.close();
}