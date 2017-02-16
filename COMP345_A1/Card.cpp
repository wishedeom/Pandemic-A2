#include "Card.h"

Card::Card(const std::string& name, const std::string& description)
	: _name{ name }
	, _description{ description }
{
	// empty
}

Card::~Card()
{
	// Empty
}

std::string Card::name() const
{
	return _name;
}

std::string Card::description() const
{
	return _description;
}

Card& Card::name(const std::string& newName)
{
	_name = newName;
	return *this;
}
