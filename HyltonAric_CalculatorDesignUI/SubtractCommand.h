#pragma once
#include "IBaseCommand.h"
class SubtractCommand :
    public IBaseCommand
{
public:
	double base, cur;
public:
	SubtractCommand(double _base, double _cur) {
		base = _base;
		cur = _cur;
	};
	double Subtract() {
		double result;
		result = base - cur;
		return result;
	};

	double Execute() {
		return Subtract();
	};
};

