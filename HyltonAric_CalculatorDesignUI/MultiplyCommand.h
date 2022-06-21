#pragma once
#include "IBaseCommand.h"
class MultiplyCommand :
    public IBaseCommand
{
public:
	double base, cur;
public:
	MultiplyCommand(double _base, double _cur) {
		base = _base;
		cur = _cur;
	};
	double Multiply() {
		double result;
		result = base * cur;
		return result;
	};

	double Execute() {
		return Multiply();
	};
};

