#include "Subject.h"


Subject::Subject(std::shared_ptr<IMediator> mediator)
	: _mediator(mediator)
{
}

Subject::~Subject()
{
}

void Subject::setMediator(std::shared_ptr<IMediator> mediator)
{
	_mediator = mediator;
}

void Subject::sendMessage(const char& data)
{
	_mediator->notify(shared_from_this(), data);
}
