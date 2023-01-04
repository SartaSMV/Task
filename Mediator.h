#pragma once

#include <set>

#include "IMediator.h"

class Mediator : public IMediator
{
public:
	Mediator();
	~Mediator();

	virtual void registerSub(std::shared_ptr <ISubject> subject) override;
	virtual void notify(const char& data) override;

private:
	std::set<std::shared_ptr <ISubject>> _registeredObjects;
};

