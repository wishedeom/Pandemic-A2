#include "Player.h"

Player::Player(const std::string& name, const Map& map)
	: _name{ name }
	, _map{ map }
	, _pawn{ std::make_unique<Pawn>(*this) }
	, _referenceCard{ std::make_unique<ReferenceCard>() }
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
	return *_pawn;
}

Card& Player::referenceCard() const
{
	return *_referenceCard;
}
