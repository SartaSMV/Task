#include "Controller.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::registerSub(std::shared_ptr<Subject> subject)
{
	if (_registeredObjects.find(subject) == _registeredObjects.end()) {
		subject->setMediator(shared_from_this());
		_registeredObjects.insert(subject);
	}
}

void Controller::notify(std::shared_ptr<Subject> subject, const char& data)
{
	for (auto i : _registeredObjects) {
		i->receiveMessage(subject, data);
	}
}
