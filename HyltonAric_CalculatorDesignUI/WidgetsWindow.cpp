#include "WidgetsWindow.h"

wxBEGIN_EVENT_TABLE(WidgetsWindow, wxFrame)
	EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()





WidgetsWindow::WidgetsWindow() : wxFrame(nullptr, wxID_ANY, "Widgets!", wxPoint(400, 200), wxSize(500, 550)) {

	wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	
	SetFont(font);

	// 1, 2 ,3
	m_btn1 = new wxButton(this, 10001, "1", wxPoint(10, 200), wxSize(100, 60));
	m_btn2 = new wxButton(this, 10002, "2", wxPoint(120, 200), wxSize(100, 60));
	m_btn3 = new wxButton(this, 10003, "3", wxPoint(230, 200), wxSize(100, 60));
	// 4, 5 ,6
	m_btn4 = new wxButton(this, 10004, "4", wxPoint(10, 270), wxSize(100, 60));
	m_btn5 = new wxButton(this, 10005, "5", wxPoint(120, 270), wxSize(100, 60));
	m_btn6 = new wxButton(this, 10006, "6", wxPoint(230, 270), wxSize(100, 60));
	// 7, 8, 9
	m_btn7 = new wxButton(this, 10007, "7", wxPoint(10, 340), wxSize(100, 60));
	m_btn8 = new wxButton(this, 10008, "8", wxPoint(120, 340), wxSize(100, 60));
	m_btn9 = new wxButton(this, 10009, "9", wxPoint(230, 340), wxSize(100, 60));
	// 0
	m_btn0 = new wxButton(this, 10000, "0", wxPoint(120, 410), wxSize(100, 60));
	// /, *, +, -, =
	m_btn_division = new wxButton(this, 10001, "/", wxPoint(340, 130), wxSize(100, 60));
	m_btn_multiply = new wxButton(this, 10002, "*", wxPoint(340, 200), wxSize(100, 60));
	m_btn_add = new wxButton(this, 10003, "+", wxPoint(340, 270), wxSize(100, 60));
	m_btn_subtract = new wxButton(this, 10002, "-", wxPoint(340, 340), wxSize(100, 60));
	m_btn_equals = new wxButton(this, 10003, "=", wxPoint(340, 410), wxSize(100, 60));
	// clear, hex, binary, mod
	m_btn_mod = new wxButton(this, 10004, "c", wxPoint(10, 130), wxSize(75, 60));
	m_btn_hex = new wxButton(this, 10005, "hex", wxPoint(92, 130), wxSize(75, 60));
	m_btn_bin = new wxButton(this, 10006, "bin", wxPoint(174, 130), wxSize(75, 60));
	m_btn_clear = new wxButton(this, 10006, "mod", wxPoint(255, 130), wxSize(75, 60));
	// negative, decimal
	m_btn_negative = new wxButton(this, 10007, "+/-", wxPoint(10, 410), wxSize(100, 60));
	m_btn_decimal = new wxButton(this, 10008, ".", wxPoint(230, 410), wxSize(100, 60));

	// inputbox
	m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 10), wxSize(463,100));
}

WidgetsWindow::~WidgetsWindow() {

}

void WidgetsWindow::OnButtonClicked(wxCommandEvent& evt) {
	//m_list1->AppendString("");
	evt.Skip();
};