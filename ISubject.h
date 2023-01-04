#pragma once

#include <memory>

class ISubject
{
public:
	ISubject() = default;
	~ISubject() = default;

	virtual void receiveMessage(const char& data) = 0;
	virtual char getSymbol() const = 0;
};

