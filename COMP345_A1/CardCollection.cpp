#include "CardCollection.h"

CardCollection& CardCollection::add(CardPtr card)
{
	_cards.push_back(std::move(card));
	return *this;
}
