#pragma once
#include <string>
#include "IBaseCommand.h"
#include <vector>
#include "AddCommand.h"
#include "SubtractCommand.h"
#include "DivideCommand.h"
#include "MultiplyCommand.h"
#include "ModCommand.h"

class CalculatorProcessor
{
private:
	CalculatorProcessor() {};
	static CalculatorProcessor* _processor;
	int baseNumber;
	int curNumber;
public:
	
	static CalculatorProcessor* GetInstance() {
		if (_processor == nullptr) {
			_processor = new CalculatorProcessor();
		}
		return _processor;
	};
	void SetBaseNumber(int number) {
		baseNumber = number;
	};
	void SetCurNumber(int number) {
		curNumber = number;
	};

	CalculatorProcessor(CalculatorProcessor& other) = delete;
	void operator=(const CalculatorProcessor& other) = delete;

	std::string GetDecimal() {
		return std::to_string(baseNumber);
	};

	std::string GetHexadecimal() {
		std::string results = "";
		int number = baseNumber;
		while (number > 0) {
			int mod = number % 16;
			if (mod % 10) {
				results = std::to_string(mod) + results;
			} 
			else if (mod == 10) {
				results = "A" + results;
			}
			else if (mod == 11) {
				results = "B" + results;
			}
			else if (mod == 12) {
				results = "C" + results;
			}
			else if (mod == 13) {
				results = "D" + results;
			}
			else if (mod == 14) {
				results = "E" + results;
			}
			else if (mod == 1) {
				results = "F" + results;
			}
			number = number / 16;
		}
		return "0x" + results;
	};

	std::string GetBinary() {
		std::string results = "";
		int number = baseNumber;
		for (int i = 0; i < 32; i++) {
			if (number % 2 == 0) {
				results = "0" + results;
			}
			else {
				results = "1" + results;
			}
			number = number / 2;
		}

		return results;
	}

	double performOperation(int const op)
	{
		std::vector<IBaseCommand*> commands;
		double result;

		double base = baseNumber;
		double cur = curNumber;

		switch (op) {
			case 0: {
				AddCommand ac(base, cur);
				commands.push_back(&ac);
				break;
			}
			case 1: {
				SubtractCommand sc(base, cur);
				commands.push_back(&sc);
				break;
			}
			case 2: {
				MultiplyCommand mc(base, cur);
				commands.push_back(&mc);
				break;
			}
			case 3: {
				DivideCommand dc(base, cur);
				commands.push_back(&dc);
				break;
			}
			case 4: {
				ModCommand modc(base, cur);
				commands.push_back(&modc);
				break;
			}
		}


		return commands[0]->Execute();
	}

	std::string OnOperationClicked(int m_op) {

		std::string result;
		switch (m_op) {
		case 0: {
			result = "+";
			break;
		}
		case 1: {
			result = "-";
			break;
		}
		case 2:
		{
			result = "*";
			break;
		}
		case 3: {
			result = "/";
			break;
		}
		case 4: {
			result = "%";
			break;
		}
		}
		return result;
	}
};

CalculatorProcessor* CalculatorProcessor::_processor = nullptr;
