#include "pch.h"
#include "CppUnitTest.h"
#include "wx/wx.h"
#include "../HyltonAric_CalculatorDesignUI/ButtonFactory.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HyltonAricCalculatorDesignUITests
{
	TEST_CLASS(CalculatorButtonFactoryTests)
	{
	public:
		ButtonFactory factory;
		wxWindow* window = new wxWindow();
		TEST_METHOD(AddButtonIDEquals1024)
		{
			wxButton* addButton = factory.CreateAddButton(window);
			Assert::AreEqual(addButton->GetId(), 1024);
		}

		TEST_METHOD(NumButton0IdEquals0)
		{
			std::vector<wxButton*> m_numButtons;
			m_numButtons.resize(10);
			std::vector<wxButton*> buttons = factory.CreateNumButtons(window, m_numButtons);
			Assert::AreEqual(buttons[0]->GetId(), 0);
		}

		TEST_METHOD(SubtractButtonIDEquals1025)
		{
			wxButton* subButton = factory.CreateSubButton(window);
			Assert::AreEqual(subButton->GetId(), 1025);
		}

		TEST_METHOD(HexLabelEqualsHex)
		{
			wxButton* hexButton = factory.CreateHexButton(window);
			std::string s = "hex";
			Assert::IsTrue(hexButton->GetLabel() == s);
		}

		TEST_METHOD(BinLabelIDEquals1030)
		{
			wxButton* binButton = factory.CreateBinButton(window);
			Assert::IsTrue(binButton->GetId() == 1030);
		}

		TEST_METHOD(DecLabelDoesntEqualEquals)
		{
			wxButton* decButton = factory.CreateDecButton(window);
			Assert::AreNotEqual(decButton->GetLabel(), "=");
		}

		TEST_METHOD(clsLabelEqualscls)
		{
			wxButton* clsButton = factory.CreateCLSButton(window);
			Assert::AreEqual(clsButton->GetLabel(), "cls");
		}

		TEST_METHOD(HexIdEquals)
		{
			wxButton* hexButton = factory.CreateHexButton(window);
			Assert::AreEqual(hexButton->GetId(), 1029);
		}

		TEST_METHOD(decIdEquals10)
		{
			wxButton* decButton = factory.CreateDecButton(window);
			Assert::AreEqual(decButton->GetId(), 10);
		}

		TEST_METHOD(signIdDoesNotEqual1026)
		{
			wxButton* signButton = factory.CreateSignButton(window);
			Assert::AreNotEqual(signButton->GetId(), 1026);
		}
	};
}

