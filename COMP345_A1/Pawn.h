#pragma once

#include <memory>

#include "City.h"
#include "Player.h"

class City;
class Player;

class Pawn
{
public:
	Pawn(const Player& owner);
	const Player& owner() const;
	const City& position() const;
	Pawn& position(const City& position);

private:
	const City* _position;
	const Player& _owner;
};
