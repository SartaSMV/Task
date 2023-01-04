#include "Mediator.h"


Mediator::Mediator() {};
Mediator::~Mediator() {};

void Mediator::registerSub(std::shared_ptr <ISubject> subject)
{
	if (_registeredObjects.find(subject) == _registeredObjects.end()) {
		_registeredObjects.insert(subject);
	}
}


void Mediator::notify(const char& data)
{
	for (std::shared_ptr <ISubject> i : _registeredObjects) {
		if(i->getSymbol() == data)
		{
			i->receiveMessage(data);
		}
	}
}