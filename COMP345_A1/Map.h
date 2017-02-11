#pragma once

#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "City.h"
#include "Player.h"

class Map
{
	using CityPtr = std::unique_ptr<City>;
	using CityPair = std::tuple<const City*, const City*>;
	using PlayerPtr = std::unique_ptr<Player>;

public:
	// Accessors
	std::string name() const;													// Map name
	const City& city(const std::string& name) const;							// Reference to city by name
	const std::vector<CityPtr>& cities() const;									// List of pointers to all contained cities
	std::vector<City*> connections(const std::string& name) const;				// List of pointers to all cities connected to given city
	bool connected(const std::string& source, const std::string& target) const;	// True iff the two cities are connected
	const std::vector<PlayerPtr>& players() const;								// List of pointers to contained players

	// Mutators
	Map& name(const std::string& name);											// Set map name
	Map& addCity(const std::string& name);										// Add city with given name
	Map& addConnection(const std::string& source, const std::string& target);	// Connect two cities with given names
	Map& addPlayer(const std::string& name);									// Add a player with a given name

private:
	std::string _name;
	std::vector<CityPtr> _cities;
	std::map<CityPair, bool> _connections;
	std::vector<PlayerPtr> _players;
};
