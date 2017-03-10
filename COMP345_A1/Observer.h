#pragma once

class Observable;

class Observer
{
public:
	Observer(Observable& model);
	virtual ~Observer();
	virtual void update() = 0;

private:
	Observable& _model;
};
