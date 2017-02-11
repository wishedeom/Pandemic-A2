#include "City.h"

#include <algorithm>
#include <stdexcept>

City::City(const std::string& name)
	: _name(name)
{}

std::string City::name() const
{
	return _name;
}

City& City::name(const std::string& name)
{
	_name = name;
	return *this;
}
