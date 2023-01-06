#pragma once

#include <memory>

#include "IMediator.h"

class IMediator;

class Subject : public std::enable_shared_from_this<Subject>
{
public:
	Subject(std::shared_ptr<IMediator> mediator = nullptr);
	~Subject();

	void setMediator(std::shared_ptr<IMediator> mediator);
	void sendMessage(const char& data);
	virtual void receiveMessage(std::shared_ptr<Subject> subject, const char& data) = 0;
private:
	std::shared_ptr<IMediator> _mediator;
};
