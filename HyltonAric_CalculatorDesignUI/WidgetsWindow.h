#pragma once

#include "wx/wx.h"

class WidgetsWindow : public wxFrame
{
public:
	WidgetsWindow();
	~WidgetsWindow();

public:

	wxButton* m_btn1 = nullptr;
	wxButton* m_btn2 = nullptr;
	wxButton* m_btn3 = nullptr;

	wxButton* m_btn4 = nullptr;
	wxButton* m_btn5 = nullptr;
	wxButton* m_btn6 = nullptr;

	wxButton* m_btn7 = nullptr;
	wxButton* m_btn8 = nullptr;
	wxButton* m_btn9 = nullptr;

	wxButton* m_btn_division = nullptr;
	wxButton* m_btn_multiply = nullptr;
	wxButton* m_btn_add = nullptr;
	wxButton* m_btn_subtract = nullptr;
	wxButton* m_btn_equals = nullptr;

	wxButton* m_btn_mod = nullptr;
	wxButton* m_btn_hex = nullptr;
	wxButton* m_btn_bin = nullptr;
	wxButton* m_btn_clear = nullptr;

	wxButton* m_btn_negative = nullptr;
	wxButton* m_btn_decimal = nullptr;

	wxButton* m_btn0 = nullptr;
	
	wxListBox* m_list1 = nullptr;

	void OnButtonClicked(wxCommandEvent& evt);
 
	wxDECLARE_EVENT_TABLE();
};

