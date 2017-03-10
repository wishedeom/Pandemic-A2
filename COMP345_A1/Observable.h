#pragma once

#include <functional>
#include <vector>

class Observer;

class Observable
{
public:
	virtual ~Observable();
	void subscribe(Observer& observer);
	void notifyAll() const;

protected:
	Observable();

private:
	void notify(Observer& observer) const;

	std::vector<std::reference_wrapper<Observer>> _observers;
};
