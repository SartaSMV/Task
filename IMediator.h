#pragma once

#include <memory>

#include "ISubject.h"


class IMediator
{
public:
	IMediator() = default;
	~IMediator() = default;

	virtual void registerSub(std::shared_ptr <ISubject> subject) = 0;
	virtual void notify(const char& data) = 0;
};

