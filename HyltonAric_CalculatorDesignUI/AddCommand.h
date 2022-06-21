#pragma once
#include "IBaseCommand.h"
class AddCommand : public IBaseCommand
{
public:
	double base, cur;
public :
	AddCommand(double _base, double _cur) {
		base = _base;
		cur = _cur;
	};
	double Add() {
		double result;
		result = base + cur;
		return result;
	};

	double Execute() {
		return Add();
	};
};

