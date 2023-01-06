#include <iostream>

#include "Controller.h"

class A : public Subject
{
public:
	A(std::shared_ptr<IMediator> mediator = nullptr) : Subject(mediator) {};
	virtual ~A() {};

	virtual void receiveMessage(std::shared_ptr<Subject> subject, const char& data) override
	{
		if(data == 'A')
		{
			std::cout << "Hellow A" << std::endl;
			sendMessage('B');
		}
		return;
	};

	void setA()
	{

	};

private:

};

class B : public Subject
{
public:
	B(std::shared_ptr<IMediator> mediator = nullptr) : Subject(mediator) {};
	virtual ~B() {};

	virtual void receiveMessage(std::shared_ptr<Subject> subject, const char& data) override
	{
		if (data == 'B')
		{
			std::cout << "Hellow B" << std::endl;
		}
		return;
	};

private:

};

class C : public Subject
{
public:
	C(std::shared_ptr<IMediator> mediator = nullptr, int a = 0) : Subject(mediator), _a(a) {};
	virtual ~C() {};

	virtual void receiveMessage(std::shared_ptr<Subject> subject, const char& data) override
	{
		if (data == 'C')
		{
			std::cout << "Hellow C. int a = " << _a << std::endl;
			_a++;
		}

		return;
	};

private:
	int _a;
};

int main()
{
	auto controller = std::make_shared<Controller>();
	auto a = std::make_shared <A>();
	auto b = std::make_shared <B>();
	auto c = std::make_shared <C>(nullptr, 8);

	controller->registerSub(std::dynamic_pointer_cast<A>(a));
	controller->registerSub(std::dynamic_pointer_cast<B>(b));
	controller->registerSub(std::dynamic_pointer_cast<C>(c));

	char ch = '8';
	while (ch != '0')
	{
		std::cout << "Input char: ";
		std::cin >> ch;
		controller->notify(nullptr, ch);
	}
	
	return 0;
}