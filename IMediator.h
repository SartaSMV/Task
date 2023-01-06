#pragma once

#include "Subject.h"

class Subject;

class IMediator : public std::enable_shared_from_this<IMediator>
{
public:
	IMediator() = default;
	~IMediator() = default;

	virtual void notify(std::shared_ptr<Subject> subject, const char& data) = 0;
};

