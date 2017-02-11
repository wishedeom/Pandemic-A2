#include "Player.h"

Player::Player(const std::string& name, const Map& map)
	: _name{ name }
	, _map{ map }
	, _pawn{ std::make_unique<Pawn>(*this) }
{
	// Empty
}

std::string Player::name() const
{
	return _name;
}

const Map& Player::map() const
{
	return _map;
}

Pawn& Player::pawn() const
{
	return *_pawn.get();
}
