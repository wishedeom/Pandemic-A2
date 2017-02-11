#pragma once

#include <memory>
#include <string>
#include <vector>

class City
{
public:
	City(const std::string& name = "");
	std::string name() const;
	City& name(const std::string& name);

private:
	std::string _name;
};
