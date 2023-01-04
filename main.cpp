#include <iostream>

#include <memory>

#include "Mediator.h"

class A : public ISubject
{
public:
	A() {};
	~A() {};

	virtual void receiveMessage(const char& data) override
	{
		std::cout << "Object A" << std::endl;
	};
	virtual char getSymbol() const override
	{
		return symbol;
	};
private:
	const char symbol = 'A';
};

class B : public ISubject
{
public:
	B() {};
	~B() {};

	virtual void receiveMessage(const char& data) override
	{
		std::cout << "Object B" << std::endl;
	};
	virtual char getSymbol() const override
	{
		return symbol;
	};

private:
	const char symbol = 'B';
};


int main()
{
	std::shared_ptr<IMediator> mediator = std::make_shared<Mediator>();
	std::shared_ptr <ISubject> a = std::make_shared<A>();
	std::shared_ptr <ISubject> b = std::make_shared<B>();

	mediator->registerSub(std::dynamic_pointer_cast<A>(a));
	mediator->registerSub(std::dynamic_pointer_cast<B>(b));

	char ch = '8';
	while (ch != '0')
	{
		std::cout << "Input char: ";
		std::cin >> ch;
		mediator->notify(ch);
	}
	
	return 0;
}