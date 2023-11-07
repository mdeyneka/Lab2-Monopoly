#include "Monolopy.h"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(string names[10],int countPlaers)
{
	for (int i = 0; i < countPlaers; i++)
	{
		Players.push_back(make_tuple(names[i], 6000));
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

std::list<std::tuple<std::string, int>> * Monopoly::GetPlayersList()
{
	return &Players;
}

std::list<std::tuple<std::string, Monopoly::Type,int,bool>> * Monopoly::GetFieldsList()
{
	return &Fields;
}

std::tuple<std::string, int> Monopoly::GetPlayerInfo(int m)
{
	list<std::tuple<std::string, int>>::iterator i = Players.begin();
	advance(i, m - 1);
	return *i;
}

bool Monopoly::Buy(int playerIndex, std::tuple<std::string, Type, int, bool> field)
{
	auto foundedPlayer = GetPlayerInfo(playerIndex); // found Player's data by index
	tuple<string, int> tempPlayer;
	list<tuple<std::string, Type, int, bool>>::iterator fieldIterator;
	list<tuple<string, int>>::iterator playerIterator = Players.begin();
	switch (get<1>(field))
	{
	case AUTO:
		if (get<2>(field)) // Check the owner
			return false; // if the owner EXIST - return
		tempPlayer = make_tuple(get<0>(foundedPlayer), get<1>(foundedPlayer) - 500); // Copy player's info with 500 money decrease
		field = make_tuple(get<0>(field), get<1>(field), playerIndex, get<2>(field)); // Copy field's info and set player index owner, flag 'already owned' as true
		break;
	case FOOD:
		if (get<2>(field))
			return false;
		tempPlayer = make_tuple(get<0>(foundedPlayer), get<1>(foundedPlayer) - 250);
		field = make_tuple(get<0>(field), get<1>(field), playerIndex, get<2>(field));
		break;
	case TRAVEL:
		if (get<2>(field))
			return false;
		tempPlayer = make_tuple(get<0>(foundedPlayer), get<1>(foundedPlayer) - 700);
		field = make_tuple(get<0>(field), get<1>(field), playerIndex, get<2>(field));
		break;
	case CLOTHER:
		if (get<2>(field))
			return false;
		tempPlayer = make_tuple(get<0>(foundedPlayer), get<1>(foundedPlayer) - 100);
		field = make_tuple(get<0>(field), get<1>(field), playerIndex, get<2>(field));
		break;
	default:
		return false;
	};
	fieldIterator = find_if(Fields.begin(), Fields.end(), [field](auto foundedPlayer) { return get<0>(foundedPlayer) == get<0>(field); }); //find field in Monopoly list
	*fieldIterator = field; //set as a new field with updated parameters
    advance(playerIterator, playerIndex-1); //move iterator according to index
	*playerIterator = tempPlayer; //set as a new player with updated parameters
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
	tuple<string, int> foundedPlayer = GetPlayerInfo(playerIndex); // found Player's data by index
	tuple<string, int> tempPlayer;

	switch (get<1>(field)) // Check type of field
	{
	case AUTO:
		if (!get<2>(field)) // Check the owner
			return false;	// if the owner NOT EXIST - return
		tempPlayer = GetPlayerInfo(get<2>(field)); //get owner of field
		tempPlayer = make_tuple(get<0>(tempPlayer), get<1>(tempPlayer) + 250); // add 250 money to owner of field
		foundedPlayer = make_tuple(get<0>(foundedPlayer), get<1>(foundedPlayer) - 250); // decrease 250 money from player 
		break;
	case FOOD:
		if (!get<2>(field))
			return false;
	case TRAVEL:
		if (!get<2>(field))
			return false;
		tempPlayer = GetPlayerInfo(get<2>(field));
		tempPlayer = make_tuple(get<0>(tempPlayer), get<1>(tempPlayer) + 250);
		foundedPlayer = make_tuple(get<0>(foundedPlayer), get<1>(foundedPlayer) - 250);
		break;
	case CLOTHER:
		if (!get<2>(field))
			return false;
		tempPlayer = GetPlayerInfo(get<2>(field));
		tempPlayer = make_tuple(get<0>(tempPlayer), get<1>(tempPlayer) + 250);
		foundedPlayer = make_tuple(get<0>(foundedPlayer), get<1>(foundedPlayer) - 250);
		break;
	case PRISON:
		foundedPlayer = make_tuple(get<0>(foundedPlayer), get<1>(foundedPlayer) - 1000);
		break;
	case BANK:
		foundedPlayer = make_tuple(get<0>(foundedPlayer), get<1>(foundedPlayer) - 700);
		break;
	default:
		return false;
	}

	/* Update both players (one with increased money, another one with decreased) */
	list<tuple<string, int>>::iterator i = Players.begin();
	advance(i, playerIndex - 1);
	*i = foundedPlayer;
	i = find_if(Players.begin(), Players.end(), [tempPlayer](auto x) { return get<0>(x) == get<0>(tempPlayer); });
	*i = tempPlayer;
	return true;
}



