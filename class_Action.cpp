#include "Hero_Game.h"

//Helper functions

// Returns true if the cell is passable
bool isPassable(char c)
{
	switch (c)
	{
	case '#':
		{
			return false;
			break;
		}
	default:
		return true;
		break;
	}
}

// Switches to next level
void nextLevel(Map &m,Hero &h, char c)
{
	if(c == '%')
	{
		if(m.getLevel() == 3 && h.getLife() > 0 )
		{
			win = true;
			isRunning = false;
		}
		else
		{
			Map temp(m.getLevel()+1);
			m = temp;
			h.setHeroPos(m);
		}
	}

}

// This function enables the hero to collect mana, sword, helmet or shield
void collect(char c, Hero &h)
{
	switch (c)
	{
	case '.':
		h.setMana(h.getMana() + 1);
		break;
	case '!':
		h.setSword(true);
		break;
	case '^':
		h.setHelmet(true);
		break;
	case '*':
		h.setShield(true);
		break;
	default:
		break;
	}
}

// Changes the level of life & power of the hero
// when meet a monster,
// depending on what he has collected
void battle(char c, Hero &h)
{
	if( c == '&' )
	{
		if( h.hasSword() && h.hasHelmet() && h.hasShield() )
		{
			h.setLife( h.getLife() - 2 );
			h.setPower( h.getPower() - 5 );
		}
		else if( h.hasSword() || h.hasHelmet() || h.hasShield() )
		{
			h.setLife( h.getLife() - 5 );
			h.setPower( h.getPower() - 7 );
		}
		else if( h.getMana() >= 5 && h.getPower() >= 0 )
		{
			h.setLife( h.getLife() - 7 );
			h.setPower( h.getPower() - 8 );
			h.setMana( h.getMana() - 5 );
		}
		else
		{
			h.setLife( h.getLife() - 10 );
			h.setPower( h.getPower() - 10 );
		}
	}
}

// Moving the hero
void Up::Act(Map &m,Hero &h)
{
	collect(m.arr[h.line-1][h.colon],h);
	battle(m.arr[h.line-1][h.colon],h);
	nextLevel(m,h,m.arr[h.line-1][h.colon]);
	if( !fail && isPassable( m.arr[h.line-1][h.colon] ))
	{
		m.arr[h.line-1][h.colon] = '$';
		m.arr[h.line][h.colon] = ' ';
		h.line -= 1;
	}
}

void Down::Act(Map &m,Hero &h)
{
	collect(m.arr[h.line+1][h.colon],h);
	battle(m.arr[h.line+1][h.colon],h);
	nextLevel(m,h,m.arr[h.line+1][h.colon]);
	if( !fail && isPassable( m.arr[h.line+1][h.colon] ) )
	{
		m.arr[h.line+1][h.colon] = '$';
		m.arr[h.line][h.colon] = ' ';
		h.line += 1;
	}
	
}

void Left::Act(Map &m,Hero &h)
{
	collect(m.arr[h.line][h.colon-1],h);
	battle(m.arr[h.line][h.colon-1],h);
	nextLevel(m,h,m.arr[h.line][h.colon-1]);
	if( !fail && isPassable( m.arr[h.line][h.colon-1] ) )
	{
		m.arr[h.line][h.colon-1] = '$';
		m.arr[h.line][h.colon] = ' ';
		h.colon -= 1;
	}
	
}

void Right::Act(Map &m,Hero &h)
{
	collect(m.arr[h.line][h.colon+1],h);
	battle(m.arr[h.line][h.colon+1],h);
	nextLevel(m,h,m.arr[h.line][h.colon+1]);
	if( !fail && isPassable( m.arr[h.line][h.colon+1] ) )
	{
		m.arr[h.line][h.colon+1] = '$';
		m.arr[h.line][h.colon] = ' ';
		h.colon += 1;
	}
	
}

// Help menu
void KeyMap::Act(Map &m, Hero &h)
{
	cout<<endl<<
		"Out of help menu -> H\n"<<
		"Go up -> W\n"<<
		"Go down -> S\n"<<
		"Go right -> D\n"<<
		"Go left -> A\n"<<
		"Exit -> Q\n"<<
		"Save game -> F\n";
	bool f = true;

	while(f)
	{
		if( getch() == 'h')
			f = false;
	}
}

// Saving game
void SaveGame::Act(Map &m, Hero &h)
{
	ofstream file("Save.dat", std::ios::binary | std::ios::trunc);
	h.SeveToFile(file);
	m.SaveMap();
}