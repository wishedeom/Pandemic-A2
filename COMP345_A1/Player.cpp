#include "Card.h"
#include "Player.h"

Player::Player(const std::string& name, const Map& map)
	: _name{ name }
	, _map{ map }
	, _pawn{ std::make_unique<Pawn>(*this) }
	, _referenceCard{ makeReferenceCard() }
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

Card& Player::roleCard() const
{
	return *_roleCard.get();
}

Player& Player::roleCard(CardPtr roleCard)
{
	_roleCard = std::move(roleCard);
	return *this;
}

CardCollection & Player::hand()
{
	return _hand;
}
