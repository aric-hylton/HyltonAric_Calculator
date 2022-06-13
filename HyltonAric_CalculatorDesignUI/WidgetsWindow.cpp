#include "WidgetsWindow.h"
#include <string>
#include <iostream>
#include <sstream>
#include <bitset>

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
	ID_MOD_BUTTON = OP_OFFSET + 4,
	ID_HEX_BUTTON,
	ID_BINARY_BUTTON,
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
	EVT_BUTTON(ID_DECI_BUTTON, OnDeciClicked)
	EVT_BUTTON(ID_SIGN_BUTTON, OnSignClicked)
	EVT_BUTTON(ID_ADD_BUTTON, OnOperationClicked)
	EVT_BUTTON(ID_SUB_BUTTON, OnOperationClicked)
	EVT_BUTTON(ID_MUL_BUTTON, OnOperationClicked)
	EVT_BUTTON(ID_DIV_BUTTON, OnOperationClicked)
	EVT_BUTTON(ID_MOD_BUTTON, OnOperationClicked)
	EVT_BUTTON(ID_CLS_BUTTON, Clear)
	EVT_BUTTON(ID_HEX_BUTTON, OnHexClicked)
	EVT_BUTTON(ID_BINARY_BUTTON, OnBinClicked)
	EVT_BUTTON(ID_EQUAL_BUTTON, OnEqualClicked)
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

void WidgetsWindow::OnSignClicked(wxCommandEvent&) {
	if (opExists) {
		if (m_postOpNum.find("-") != std::string::npos) {
			m_postOpNum.replace(0, 1, "");
		}
		else {
			m_postOpNum.insert(0, "-");
		}
	}
	else {
		if (m_preOpNum.find("-") != std::string::npos) {
			m_preOpNum.replace(0, 1, "");
		}
		else {
			m_preOpNum.insert(0, "-");
		}

		if (m_preOpNum.length() != 1) {
			m_total = std::stod(m_preOpNum);
		}
	}
	updateDisplay();
};

void WidgetsWindow::OnDeciClicked(wxCommandEvent&) {
	if (opExists) {
		m_postOpNum += ".";
	}
	else {
		m_preOpNum += ".";
	}
	updateDisplay();
};

void WidgetsWindow::OnBinClicked(wxCommandEvent&) {
	if (!opExists) {
		int y = round(m_total);
		std::string binary = std::bitset<8>(m_total).to_string();
		m_TextCtrl->SetValue(binary);

		m_preOpNum.assign("");
	}
};

void WidgetsWindow::OnHexClicked(wxCommandEvent&) {

	std::string hexString;
	if (!opExists ) {
		if (!hex) {
			std::ostringstream ss;
			ss << "0x" << std::hexfloat << m_total;
			hexString = ss.str();
			m_TextCtrl->SetValue(hexString);

			hex = true;
		}
		else {
			std::stringstream ss;
			ss << std::hex << hexString;
			ss >> m_total;
			m_TextCtrl->SetValue(std::to_string(m_total));

			hex = false;
		}
		m_preOpNum.assign("");
	}
};

void WidgetsWindow::OnOperationClicked(wxCommandEvent& evt) {
	if (!opExists) {
		opExists = true;
		int OP = evt.GetId();
		m_op = OP - OP_OFFSET;
		switch (OP) {
		case ID_ADD_BUTTON: {
			m_preOpNum += "+";
			break;
		}
		case ID_SUB_BUTTON: {
			m_preOpNum += "-";
			break;
		}
		case ID_MUL_BUTTON:
		{
			m_preOpNum += "*";
			break;
		}
		case ID_DIV_BUTTON: {
			m_preOpNum += "/";
			break;
		}
		case ID_MOD_BUTTON: {
			m_preOpNum += "%";
			break;
		}
		}
		updateDisplay();
	}
	
	evt.Skip();
};

void WidgetsWindow::OnEqualClicked(wxCommandEvent& evt) {
	double result = 0;
	if (m_op >= 0) {
		result = performOperation(m_total, m_cur, m_op);
	}
	m_TextCtrl->SetValue(std::to_string(result));

	m_postOpNum.assign("");
	m_preOpNum.assign(m_TextCtrl->GetValue());
	m_total = result;

	opExists = false;
};

void WidgetsWindow::updateDisplay()
{
	std::string numStr("");
	numStr.append(m_preOpNum);
	numStr.append(m_postOpNum);
	
	m_TextCtrl->SetValue(numStr);
}

void WidgetsWindow::onNumButton(wxCommandEvent&, int NUM)
{
	if (opExists) {
		m_postOpNum += std::to_string(NUM);
		m_cur = std::stod(m_postOpNum);
	}
	else {
		m_preOpNum += std::to_string(NUM);
		m_total = std::stod(m_preOpNum);
	}
	updateDisplay();
}


void WidgetsWindow::Clear(wxCommandEvent&)
{
	opExists = false;
	m_total = 0;
	m_cur = 0;
	m_preOpNum.assign("");
	m_postOpNum.assign("");
	m_TextCtrl->SetValue("");
}

double WidgetsWindow::performOperation(double const left, double const right, int const op)
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
			result = 0;
		}
		break;
	}
	case OP_MOD: {
		result = (int)left % (int)right;
		break;
	}
	}

	return result;
}