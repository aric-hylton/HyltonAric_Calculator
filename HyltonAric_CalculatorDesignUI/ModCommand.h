#pragma once
#include "IBaseCommand.h"
class ModCommand :
    public IBaseCommand
{
public:
	double base, cur;
public:
	ModCommand(double _base, double _cur) {
		base = _base;
		cur = _cur;
	};
	double Mod() {
		double result;
		result = (int)base % (int)cur;
		return result;
	};

	double Execute() {
		return Mod();
	};
};

