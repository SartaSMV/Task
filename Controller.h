#pragma once

#include <set>

#include "IMediator.h"


class Controller : public IMediator
{
public:
	Controller();
	~Controller();

	void registerSub(std::shared_ptr<Subject> subject);
	virtual void notify(std::shared_ptr<Subject> subject, const char& data) override;
private:
	std::set<std::shared_ptr<Subject>> _registeredObjects;
};
