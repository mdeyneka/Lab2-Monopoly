#pragma once

#include <list>
#include <tuple>
#include <string>

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
	std::list<std::tuple<std::string,int>> *	GetPlayersList();
	std::list<std::tuple<std::string, Type, int,bool>> * GetFieldsList();
	std::list<std::tuple<std::string, Type, int, bool>> Fields;
	std::list<std::tuple<std::string, int>> Players;
	std::tuple<std::string, int>  GetPlayerInfo(int);	 
	bool Buy(int p,std::tuple<std::string, Type, int, bool>);
	std::tuple<std::string, Type, int, bool> GetFieldByName(std::string);	
	bool Renta(int p, std::tuple<std::string, Type, int, bool>c);
	
};

