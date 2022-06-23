#include "pch.h"
#include "CppUnitTest.h"
#include "../HyltonAric_CalculatorDesignUI/CalculatorProcessor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HyltonAricCalculatorDesignUITests
{
	TEST_CLASS(CalculatorProcessorTests)
	{
	public:
		
		CalculatorProcessor* processor = CalculatorProcessor::GetInstance();

		TEST_METHOD(AddFivePlusSixEqualsEleven)
		{
			processor->SetBaseNumber(5);
			processor->SetCurNumber(6);

			double answer = processor->performOperation(0);
			Assert::AreEqual(answer, 11.0);
		}

		TEST_METHOD(MultiplyFiveTimeSixEqualsThirty)
		{
			processor->SetBaseNumber(5);
			processor->SetCurNumber(6);

			double answer = processor->performOperation(2);
			Assert::AreEqual(answer, 30.0);
		}

		TEST_METHOD(DivideThirtyBySixDoesNotEqualEleven)
		{
			processor->SetBaseNumber(30);
			processor->SetCurNumber(6);

			double answer = processor->performOperation(3);
			Assert::AreNotEqual(answer, 11.0);
		}

		TEST_METHOD(FortyMinusTwentyFiveEqualsFifteen)
		{
			processor->SetBaseNumber(40);
			processor->SetCurNumber(25);

			double answer = processor->performOperation(1);
			Assert::AreEqual(answer, 15.0);
		}

		TEST_METHOD(AddFivePlusSixDoesNotEqualEight)
		{
			processor->SetBaseNumber(5);
			processor->SetCurNumber(6);

			double answer = processor->performOperation(0);
			Assert::AreNotEqual(answer, 8.0);
		}

		TEST_METHOD(HexadecimalOfFiveSixtyFiveEqualsZeroXTwoThreeFive)
		{
			processor->SetBaseNumber(565);

			std::string answer = processor->GetHexadecimal();
			std::string s = "0x235";
			Assert::AreEqual(answer, s);
		}

		TEST_METHOD(HexadecimalOfTwoSixtySixEqualsZeroXOneA)
		{
			processor->SetBaseNumber(266);

			std::string answer = processor->GetHexadecimal();
			std::string s = "0x1A";
			Assert::AreEqual(answer, s);
		}

		TEST_METHOD(BinaryOfFiveEqualsOneZeroOne)
		{
			processor->SetBaseNumber(5);

			std::string answer = processor->GetBinary();
			std::string s = "00000000000000000000000000000101";
			Assert::AreEqual(answer, s);
		}

		TEST_METHOD(BinaryOfTenNotEqualsTwoZeroTwo)
		{
			processor->SetBaseNumber(10);
			std::string answer = processor->GetBinary();
			std::string s = "00000000000000000000000000000202";
			Assert::AreNotEqual(answer, s);
		}

		TEST_METHOD(SevenModFiveEqualsTwo)
		{
			processor->SetBaseNumber(7);
			processor->SetCurNumber(5);

			double answer = processor->performOperation(4);
			Assert::AreEqual(answer, 2.0);
		}
	};
}
