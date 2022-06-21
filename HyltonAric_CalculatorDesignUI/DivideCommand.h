#pragma once
#include "IBaseCommand.h"
class DivideCommand :
    public IBaseCommand
{
public:
	double base, cur;
public:
	DivideCommand(double _base, double _cur) {
		base = _base;
		cur = _cur;
	};
	double Divide() {
		double result;

		if (cur != 0) {
			result = base / cur;
		}
		else {
			result = 0;
		}
		return result;
	};

	double Execute() {
		return Divide();
	};
};

