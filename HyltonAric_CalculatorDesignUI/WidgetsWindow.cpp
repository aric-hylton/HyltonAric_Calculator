#include "WidgetsWindow.h"

const int OP_OFFSET = 1024;

enum event_ids {
	// important these map to the numbers
	ID_0_BUTTON = 0,
	ID_1_BUTTON = 1,
	ID_2_BUTTON = 2,
	ID_3_BUTTON = 3,
	ID_4_BUTTON = 4,
	ID_5_BUTTON = 5,
	ID_6_BUTTON = 6,
	ID_7_BUTTON = 7,
	ID_8_BUTTON = 8,
	ID_9_BUTTON = 9,
	ID_DECI_BUTTON,
	ID_SIGN_BUTTON,
	ID_ADD_BUTTON = OP_OFFSET + 0,
	ID_SUB_BUTTON = OP_OFFSET + 1,
	ID_MUL_BUTTON = OP_OFFSET + 2,
	ID_DIV_BUTTON = OP_OFFSET + 3,
	ID_HEX_BUTTON,
	ID_BINARY_BUTTON,
	ID_MOD_BUTTON,
	ID_CLS_BUTTON,
	ID_EQUAL_BUTTON
};


wxBEGIN_EVENT_TABLE(WidgetsWindow, wxFrame)
	EVT_BUTTON(ID_0_BUTTON, OnNumClicked)
	EVT_BUTTON(ID_1_BUTTON, OnNumClicked)
	EVT_BUTTON(ID_2_BUTTON, OnNumClicked)
	EVT_BUTTON(ID_3_BUTTON, OnNumClicked)
	EVT_BUTTON(ID_4_BUTTON, OnNumClicked)
	EVT_BUTTON(ID_5_BUTTON, OnNumClicked)
	EVT_BUTTON(ID_6_BUTTON, OnNumClicked)
	EVT_BUTTON(ID_7_BUTTON, OnNumClicked)
	EVT_BUTTON(ID_8_BUTTON, OnNumClicked)
	EVT_BUTTON(ID_9_BUTTON, OnNumClicked)
	EVT_BUTTON(ID_DECI_BUTTON, OnNumClicked)
	EVT_BUTTON(ID_SIGN_BUTTON, OnNumClicked)
	EVT_BUTTON(ID_ADD_BUTTON, OnOperationClicked)
	EVT_BUTTON(ID_SUB_BUTTON, OnOperationClicked)
	EVT_BUTTON(ID_MUL_BUTTON, OnOperationClicked)
	EVT_BUTTON(ID_DIV_BUTTON, OnOperationClicked)
	EVT_BUTTON(ID_CLS_BUTTON, Clear)
	EVT_BUTTON(ID_HEX_BUTTON, OnNumClicked)
	EVT_BUTTON(ID_BINARY_BUTTON, OnNumClicked)
	EVT_BUTTON(ID_MOD_BUTTON, OnNumClicked)
	EVT_BUTTON(ID_EQUAL_BUTTON, OnNumClicked)
wxEND_EVENT_TABLE()





WidgetsWindow::WidgetsWindow() : wxFrame(nullptr, wxID_ANY, "Widgets!", wxPoint(400, 200), wxSize(500, 550)) {

	wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	
	SetFont(font);

	wxGridSizer* buttonSizer = new wxGridSizer(4, 0, 0);

	wxSize buttonSize(100, 60);

	// create 1-9
	int xPos = 10,
		yPos = 200;
	m_numButtons.resize(10);
	for (int num = 1; num < 10; ++num) {
		m_numButtons[num] = new wxButton(this, num, std::to_string(num), \
			wxPoint(xPos, yPos), buttonSize);
		xPos += 110;
		if (num % 3 == 0) {
			yPos += 70;
			xPos = 10;
		}
	}
	// create 0
	m_btn0 = new wxButton(this, 0, "0", wxPoint(120, 410), wxSize(100, 60));

	// /, *, +, -, =
	m_btn_division = new wxButton(this, ID_DIV_BUTTON, "/", wxPoint(340, 130), wxSize(100, 60));
	m_btn_multiply = new wxButton(this, ID_MUL_BUTTON, "*", wxPoint(340, 200), wxSize(100, 60));
	m_btn_add = new wxButton(this, ID_ADD_BUTTON, "+", wxPoint(340, 270), wxSize(100, 60));
	m_btn_subtract = new wxButton(this, ID_SUB_BUTTON, "-", wxPoint(340, 340), wxSize(100, 60));
	m_btn_equals = new wxButton(this, ID_EQUAL_BUTTON, "=", wxPoint(340, 410), wxSize(100, 60));
	// clear, hex, binary, mod
	m_btn_mod = new wxButton(this, ID_CLS_BUTTON, "c", wxPoint(10, 130), wxSize(75, 60));
	m_btn_hex = new wxButton(this, ID_HEX_BUTTON, "hex", wxPoint(92, 130), wxSize(75, 60));
	m_btn_bin = new wxButton(this, ID_BINARY_BUTTON, "bin", wxPoint(174, 130), wxSize(75, 60));
	m_btn_clear = new wxButton(this, ID_MOD_BUTTON, "mod", wxPoint(255, 130), wxSize(75, 60));
	// negative, decimal
	m_btn_negative = new wxButton(this, ID_SIGN_BUTTON, "+/-", wxPoint(10, 410), wxSize(100, 60));
	m_btn_decimal = new wxButton(this, ID_DECI_BUTTON, ".", wxPoint(230, 410), wxSize(100, 60));

	// inputbox
	m_TextCtrl = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 10), wxSize(463, 100), wxTE_RIGHT);
}

WidgetsWindow::~WidgetsWindow() {

}

void WidgetsWindow::OnNumClicked(wxCommandEvent& evt) {
	
	onNumButton(evt, evt.GetId());
	evt.Skip();
};

void WidgetsWindow::OnOperationClicked(wxCommandEvent& evt) {

	onNumButton(evt, evt.GetId());
	evt.Skip();
};

void WidgetsWindow::updateDisplay()
{
	std::string numStr("");

	numStr += m_preDecimal;

	m_TextCtrl->SetValue(numStr);
}

void WidgetsWindow::onNumButton(wxCommandEvent&, int NUM)
{
	m_preDecimal += std::to_string(NUM);
	updateDisplay();
}

void WidgetsWindow::Clear(wxCommandEvent&)
{
	m_preDecimal = "";
	m_TextCtrl->SetValue("");
}

double WidgetsWindow::performOperation(
	double const left,
	double const right,
	int const op)
{
	double result;

	switch (op) {
	case OP_ADD: {
		result = left + right;
		break;
	}
	case OP_SUB: {
		result = left - right;
		break;
	}
	case OP_MUL: {
		result = left * right;
		break;
	}
	case OP_DIV: {
		if (right != 0) {
			result = left / right;
		}
		else {
			throw std::runtime_error("Cannot divide by zero.");
		}
		break;
	}
	default: {
		// TODO: handle this in a meaningful way for the user.
		throw std::runtime_error("Unknown OP: " + std::to_string(op));
	}
	}

	return result;
}