#pragma once

#include <list>
#include <vector>
#include <tuple>
#include <string>
#include "Player.h"

class Monopoly
{
public:
	enum Type
	{
		AUTO,
		FOOD,
		TRAVEL,
		CLOTHER,
		PRISON,
		BANK
	};
	Monopoly(std::string names[10],int);
	std::vector<Player>* GetPlayers();
	std::list<std::tuple<std::string, Type, int,bool>> * GetFieldsList();
	std::list<std::tuple<std::string, Type, int, bool>> Fields;
	std::vector<Player> players;
	Player*  GetPlayer(int);
	bool Buy(int p,std::tuple<std::string, Type, int, bool>);
	std::tuple<std::string, Type, int, bool> GetFieldByName(std::string);	
	bool Renta(int p, std::tuple<std::string, Type, int, bool>c);
	
};

