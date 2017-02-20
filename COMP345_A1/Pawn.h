#pragma once

#include <memory>

#include "City.h"
#include "Player.h"

class City;
class Player;

// Represents a player's pawn
class Pawn
{
public:
	Pawn(const Player& owner);				// Ctor
	const Player& owner() const;			// Gets owner
	const City& position() const;			// Gets position
	Pawn& position(const City& position);	// Changes position

private:
	const City* _position;
	const Player& _owner;
};
