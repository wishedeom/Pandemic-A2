#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
public:
	Card(const std::string& name, const std::string& description);
	Card(const Card& original);
	const std::string& name() const;
	const std::string& description() const;
	Card& name(const std::string& newName);

private:
	std::string _name;
	std::string _description;
};

#endif // CARD_H
