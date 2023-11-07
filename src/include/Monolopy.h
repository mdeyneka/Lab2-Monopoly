#pragma once

#include <vector>
#include <string>
#include "Player.h"
#include <Field.h>

class Monopoly
{
public:
	Monopoly(std::string names[10],int);
	std::vector<Player>* GetPlayers();
	std::vector<Field>* GetFields();
	Player* GetPlayer(int);
	bool Buy(int p, Field* field);
	Field* GetFieldByName(const std::string& name);	
	bool Renta(int p, Field* field);

private:
	std::vector<Field> fields;
	std::vector<Player> players;
};

