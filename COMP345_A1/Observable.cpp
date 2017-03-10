#include "Observable.h"
#include "Observer.h"

Observable::Observable() {}

Observable::~Observable() {}

void Observable::subscribe(Observer& observer)
{
	_observers.push_back(observer);
}

void Observable::notifyAll() const
{
	for (auto& observer : _observers)
	{
		notify(observer);
	}
}

void Observable::notify(Observer& observer) const
{
	observer.update();
}
