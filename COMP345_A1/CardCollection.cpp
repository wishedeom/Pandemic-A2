#include "CardCollection.h"

CardCollection& CardCollection::add(CardPtr card)
{
	_cards.push_back(std::move(card));
	return *this;
}

std::unique_ptr<Card> CardCollection::draw()
{
	auto top = std::move(_cards.back());
	_cards.pop_back();
	return std::move(top);
}
