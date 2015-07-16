#pragma once

class Hero
{
	// Hero's current life, power & mana points
	float life, power;
	int mana;

	// Three boolean variables telling what the hero has collected
	bool sword, helmet, shield;

public:

	// Constructors & destructor
	Hero(): 
		life(100),power(100),mana(0),
		sword(false),helmet(false),shield(false) {}
	~Hero(){}
	Hero(float l, float p,int m,bool s,bool h, bool sh):
		life(l), power(p), mana(m),
		sword(s), helmet(h), shield(sh) {}

	// Crates new hero from a binary file
	Hero(std::ifstream &file);

	// Indexers of the hero's position
	int line, colon;
	

	// Setters & getters for every variable
	//
	void setLife(float l);
	float getLife()const { return life; }

	void setPower(float p);
	float getPower()const { return power; }

	void setMana(int m) { mana = m; }
	int getMana() const { return mana; }

	void setSword(bool b) { sword = b; }
	bool hasSword() const { return sword;}

	void setHelmet(bool b) { helmet = b; }
	bool hasHelmet() const { return helmet; }

	void setShield(bool b) { shield = b; }
	bool hasShield() const { return shield; }

	// Sets line & colon of the hero
	void setHeroPos(Map &m);

	// Prints the table of the hero
	void Print() const ;

	// Saves all the information about the hero in a binary file
	void SeveToFile(std::ofstream &file);

};

