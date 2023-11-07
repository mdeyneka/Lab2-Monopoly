#include "Monolopy.h"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(string names[10],int countPlaers)
{
	for (int i = 0; i < countPlaers; i++)
	{
		players.push_back({names[i], 6000});
	}
	Fields.push_back(make_tuple("Ford", Monopoly::AUTO, 0, false));
	Fields.push_back(make_tuple("MCDonald", Monopoly::FOOD, 0, false));
	Fields.push_back(make_tuple("Lamoda", Monopoly::CLOTHER, 0, false));
	Fields.push_back(make_tuple("Air Baltic", Monopoly::TRAVEL, 0, false));
	Fields.push_back(make_tuple("Nordavia", Monopoly::TRAVEL, 0, false));
	Fields.push_back(make_tuple("Prison", Monopoly::PRISON, 0, false));
	Fields.push_back(make_tuple("MCDonald", Monopoly::FOOD, 0, false));
	Fields.push_back(make_tuple("TESLA", Monopoly::AUTO, 0, false));
}

std::vector<Player>* Monopoly::GetPlayers()
{
	return &players;
}

std::list<std::tuple<std::string, Monopoly::Type,int,bool>> * Monopoly::GetFieldsList()
{
	return &Fields;
}

Player* Monopoly::GetPlayer(int m)
{
	std::vector<Player>::iterator i = players.begin();
	advance(i, m - 1);
	return &*i;
}

bool Monopoly::Buy(int playerIndex, std::tuple<std::string, Type, int, bool> field)
{
	Player* foundedPlayer = GetPlayer(playerIndex);
	list<tuple<std::string, Type, int, bool>>::iterator fieldIterator;
	switch (get<1>(field))
	{
	case AUTO:
		if (get<2>(field)) // Check the owner
			return false; // if the owner EXIST - return
		foundedPlayer->SubtractMoney(500);
		field = make_tuple(get<0>(field), get<1>(field), playerIndex, get<2>(field)); // Copy field's info and set player index owner, flag 'already owned' as true
		break;
	case FOOD:
		if (get<2>(field))
			return false;
		foundedPlayer->SubtractMoney(250);
		field = make_tuple(get<0>(field), get<1>(field), playerIndex, get<2>(field));
		break;
	case TRAVEL:
		if (get<2>(field))
			return false;
		foundedPlayer->SubtractMoney(700);
		field = make_tuple(get<0>(field), get<1>(field), playerIndex, get<2>(field));
		break;
	case CLOTHER:
		if (get<2>(field))
			return false;
		foundedPlayer->SubtractMoney(100);
		field = make_tuple(get<0>(field), get<1>(field), playerIndex, get<2>(field));
		break;
	default:
		return false;
	};
	fieldIterator = find_if(Fields.begin(), Fields.end(), [field](auto foundedPlayer) { return get<0>(foundedPlayer) == get<0>(field); }); //find field in Monopoly list
	*fieldIterator = field; //set as a new field with updated parameters
	return true;
}

std::tuple<std::string, Monopoly::Type, int, bool>  Monopoly::GetFieldByName(std::string l)
{
	std::list<std::tuple<std::string, Monopoly::Type, int, bool>>::iterator i = find_if(Fields.begin(), Fields.end(),[l] (std::tuple<std::string, Monopoly::Type, int, bool> x) {
		return get<0>(x) == l;
	});
	return *i;
}

bool Monopoly::Renta(int playerIndex, std::tuple<std::string, Type, int, bool> field)
{
	Player* foundedPlayer = GetPlayer(playerIndex);
	Player* tempPlayer;

	switch (get<1>(field)) // Check type of field
	{
	case AUTO:
		if (!get<2>(field)) // Check the owner
			return false;	// if the owner NOT EXIST - return
		tempPlayer = GetPlayer(get<2>(field));
		tempPlayer->AddMoney(250);
		foundedPlayer->SubtractMoney(250);
		break;
	case FOOD:
		if (!get<2>(field))
			return false;
	case TRAVEL:
		if (!get<2>(field))
			return false;
		tempPlayer = GetPlayer(get<2>(field));
		tempPlayer->AddMoney(250);
		foundedPlayer->SubtractMoney(250);
		break;
	case CLOTHER:
		if (!get<2>(field))
			return false;
		tempPlayer = GetPlayer(get<2>(field));
		tempPlayer->AddMoney(250);
		foundedPlayer->SubtractMoney(250);
		break;
	case PRISON:
		foundedPlayer->SubtractMoney(1000);
		break;
	case BANK:
		foundedPlayer->SubtractMoney(750);
		break;
	default:
		return false;
	}
	return true;
}



