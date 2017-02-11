#include "Map.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>

std::string Map::name() const
{
	return _name;
}

Map& Map::name(const std::string & name)
{
	_name = name;
	return *this;
}

Map& Map::addCity(const std::string& name)
{
	_cities.push_back(std::make_unique<City>(name));
	return *this;
}

Map& Map::addConnection(const std::string& source, const std::string& target)
{
	const City* city1 = &city(source);
	const City* city2 = &city(target);
	_connections[std::make_pair(city1, city2)] = true;
	_connections[std::make_pair(city2, city1)] = true;
	return *this;
}

Map& Map::addPlayer(const std::string& name)
{
	_players.push_back(std::make_unique<Player>(name, *this));
	return *this;
}

const City& Map::city(const std::string& name) const
{
	const auto it = std::find_if(_cities.begin(), _cities.end(),
		[&](const std::unique_ptr<City>& cityPtr) -> bool
		{
			return cityPtr->name() == name;
		});
	if (it == _cities.end())
		throw std::out_of_range{ "No city of that name exits." };
	return *it->get();
}

const std::vector<Map::CityPtr>& Map::cities() const
{
	return _cities;
}

std::vector<City*> Map::connections(const std::string& name) const
{
	std::vector<City*> connVec;
	for (const auto& city : _cities)
		if (connected(name, city->name()))
			connVec.push_back(city.get());
	return connVec;
}

bool Map::connected(const std::string& source, const std::string& target) const
{
	auto it = _connections.find(std::make_pair(&city(source), &city(target)));
	return it != _connections.end() && it->second;
}

const std::vector<Map::PlayerPtr>& Map::players() const
{
	return _players;
}
