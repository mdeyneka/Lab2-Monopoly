#include "Monolopy.h"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(string names[10],int countPlaers)
{
	for (int i = 0; i < countPlaers; i++)
	{
		players.push_back({names[i], 6000});
	}
	fields.push_back({"Ford", Field::Type::AUTO});
	fields.push_back({"MCDonald", Field::Type::FOOD});
	fields.push_back({"Lamoda", Field::Type::CLOTHER});
	fields.push_back({"Air Baltic", Field::Type::TRAVEL});
	fields.push_back({"Nordavia", Field::Type::TRAVEL});
	fields.push_back({"Prison", Field::Type::PRISON});
	fields.push_back({"MCDonald", Field::Type::FOOD});
	fields.push_back({"TESLA", Field::Type::AUTO});
}

std::vector<Player>* Monopoly::GetPlayers()
{
	return &players;
}

std::vector<Field>* Monopoly::GetFields()
{
	return &fields;
}

Player* Monopoly::GetPlayer(int m)
{
	std::vector<Player>::iterator i = players.begin();
	advance(i, m - 1);
	return &*i;
}

bool Monopoly::Buy(int playerIndex, Field* field)
{
	Player* foundedPlayer = GetPlayer(playerIndex);
	//list<tuple<std::string, Type, int, bool>>::iterator fieldIterator;
	switch (field->GetType())
	{
	case Field::Type::AUTO:
		if (field->IsOwnerExist())
			return false;
		foundedPlayer->SubtractMoney(500);
		field->SetOwner(foundedPlayer);
		break;
	case Field::Type::FOOD:
		if (field->IsOwnerExist())
			return false;
		foundedPlayer->SubtractMoney(250);
		field->SetOwner(foundedPlayer);
		break;
	case Field::Type::TRAVEL:
		if (field->IsOwnerExist())
			return false;
		foundedPlayer->SubtractMoney(700);
		field->SetOwner(foundedPlayer);
		break;
	case Field::Type::CLOTHER:
		if (field->IsOwnerExist())
			return false;
		foundedPlayer->SubtractMoney(100);
		field->SetOwner(foundedPlayer);
		break;
	default:
		return false;
	};
	return true;
}

Field* Monopoly::GetFieldByName(const std::string& name)
{
	std::vector<Field>::iterator i = find_if(fields.begin(), fields.end(),[name] (Field x) {
		return x.GetName() == name;
	});
	return &*i;
}

bool Monopoly::Renta(int playerIndex, Field* field)
{
	Player* foundedPlayer = GetPlayer(playerIndex);
	Player* tempPlayer;

	switch (field->GetType())
	{
	case Field::Type::AUTO:
		if (!field->IsOwnerExist())
			return false;
		tempPlayer = field->GetOwner();
		tempPlayer->AddMoney(250);
		foundedPlayer->SubtractMoney(250);
		break;
	case Field::Type::FOOD:
		if (!field->IsOwnerExist())
			return false;
	case Field::Type::TRAVEL:
		if (!field->IsOwnerExist())
			return false;
		tempPlayer = field->GetOwner();
		tempPlayer->AddMoney(250);
		foundedPlayer->SubtractMoney(250);
		break;
	case Field::Type::CLOTHER:
		if (!field->IsOwnerExist())
			return false;
		tempPlayer = field->GetOwner();
		tempPlayer->AddMoney(250);
		foundedPlayer->SubtractMoney(250);
		break;
	case Field::Type::PRISON:
		foundedPlayer->SubtractMoney(1000);
		break;
	case Field::Type::BANK:
		foundedPlayer->SubtractMoney(750);
		break;
	default:
		return false;
	}
	return true;
}



