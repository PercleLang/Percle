#pragma once

class TokenData;

#include <memory>
using std::shared_ptr;

#include <string>
using std::string;

class AllOperators;

class OperatorData {
public:
	enum InputTaken	{
		LEFT,
		RIGHT,
		BOTH,
	};
	
	string getText() {return text;}
	int getPrecedence() {return precedence;}
	bool isOverloadable() {return overloadable;}
	bool takesLeftInput() {return input==BOTH || input==LEFT;}
	bool takesRightInput() {return input==BOTH || input==RIGHT;}
	
private:
	
	friend AllOperators;
	
	OperatorData(string textIn, int precedenceIn, InputTaken inputIn, bool overloadableIn)
	{
		text         = textIn;
		precedence   = precedenceIn;
		input        = inputIn;
		overloadable = overloadableIn;
	}
	
	string text;
	
	int precedence;
	bool overloadable;
	
	InputTaken input;
};

typedef shared_ptr<OperatorData> Operator;
