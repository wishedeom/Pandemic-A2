#include "City.h"

#include <algorithm>
#include <stdexcept>

City::City(const std::string& name, const std::string& colour)
	: _name(name)
	, _colour(colour)
{}

std::string City::name() const
{
	return _name;
}

std::string City::colour() const
{
	return _colour;
}

City& City::name(const std::string& name)
{
	_name = name;
	return *this;
}

City& City::colour(const std::string & colour)
{
	_colour = colour;
	return *this;
}
