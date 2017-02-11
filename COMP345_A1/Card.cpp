#include "Card.h"

Card::Card(const std::string& name, const std::string& description)
	: _name{ name }
	, _description{ description }
{
	// empty
}

Card::Card(const Card& original)
	: _name{ original._name }
	, _description{ original._description }
{
	// empty
}

const std::string& Card::name() const
{
	return _name;
}

Card& Card::name(const std::string& newName)
{
	_name = newName;
	return *this;
}
