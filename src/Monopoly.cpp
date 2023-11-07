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

bool Monopoly::Buy(int z, std::tuple<std::string, Type, int, bool> k)
{
	auto x = GetPlayerInfo(z);
	tuple<string, int> p;
	list<tuple<std::string, Type, int, bool>>::iterator i;
	list<tuple<string, int>>::iterator j = Players.begin();
	switch (get<1>(k))
	{
	case AUTO:
		if (get<2>(k))
			return false;
		p = make_tuple(get<0>(x), get<1>(x) - 500);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
		break;
	case FOOD:
		if (get<2>(k))
			return false;
		p = make_tuple(get<0>(x), get<1>(x) - 250);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
		break;
	case TRAVEL:
		if (get<2>(k))
			return false;
		p = make_tuple(get<0>(x), get<1>(x) - 700);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
		break;
	case CLOTHER:
		if (get<2>(k))
			return false;
		p = make_tuple(get<0>(x), get<1>(x) - 100);
		k = make_tuple(get<0>(k), get<1>(k), z, get<2>(k));
		break;
	default:
		return false;
	};
	i = find_if(Fields.begin(), Fields.end(), [k](auto x) { return get<0>(x) == get<0>(k); });
	*i = k;
    advance(j, z-1);
	*j = p;
	return true;
}

std::tuple<std::string, Monopoly::Type, int, bool>  Monopoly::GetFieldByName(std::string l)
{
	std::list<std::tuple<std::string, Monopoly::Type, int, bool>>::iterator i = find_if(Fields.begin(), Fields.end(),[l] (std::tuple<std::string, Monopoly::Type, int, bool> x) {
		return get<0>(x) == l;
	});
	return *i;
}

bool Monopoly::Renta(int m, std::tuple<std::string, Type, int, bool> c)
{
	tuple<string, int> z = GetPlayerInfo(m);
	tuple<string, int> o;

	switch (get<1>(c))
	{
	case AUTO:
		if (!get<2>(c))
			return false;
		o = GetPlayerInfo(get<2>(c));
		o = make_tuple(get<0>(o), get<1>(o) + 250);
		z = make_tuple(get<0>(z), get<1>(z) - 250);
		break;
	case FOOD:
		if (!get<2>(c))
			return false;
	case TRAVEL:
		if (!get<2>(c))
			return false;
		o = GetPlayerInfo(get<2>(c));
		o = make_tuple(get<0>(o), get<1>(o) + 250);
		z = make_tuple(get<0>(z), get<1>(z) - 250);
		break;
	case CLOTHER:
		if (!get<2>(c))
			return false;
		o = GetPlayerInfo(get<2>(c));
		o = make_tuple(get<0>(o), get<1>(o) + 250);
		z = make_tuple(get<0>(z), get<1>(z) - 250);
		break;
	case PRISON:
		z = make_tuple(get<0>(z), get<1>(z) - 1000);
		break;
	case BANK:
		z = make_tuple(get<0>(z), get<1>(z) - 700);
		break;
	default:
		return false;
	}
	list<tuple<string, int>>::iterator i = Players.begin();
	advance(i, m - 1);
	*i = z;
	i = find_if(Players.begin(), Players.end(), [o](auto x) { return get<0>(x) == get<0>(o); });
	*i = o;
	return true;
}



