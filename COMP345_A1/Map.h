#pragma once

#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "City.h"
#include "Player.h"

using CityPtr = std::unique_ptr<City>;
using CityPair = std::tuple<const City*, const City*>;
using PlayerPtr = std::unique_ptr<Player>;

class Map
{
public:
	// Accessors
	std::string name() const;
	const City& city(const std::string& name) const;
	const std::vector<CityPtr>& cities() const;
	std::vector<City*> connections(const std::string& name) const;
	bool connected(const std::string& source, const std::string& target) const;
	const std::vector<PlayerPtr>& players() const;

	// Mutators
	Map& name(const std::string& name);
	Map& addCity(const std::string& name);
	Map& addConnection(const std::string& source, const std::string& target);
	Map& addPlayer(const std::string& name);

private:
	std::string _name;
	std::vector<CityPtr> _cities;
	std::map<CityPair, bool> _connections;
	std::vector<PlayerPtr> _players;
};
