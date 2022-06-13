#pragma once

#include "wx/wx.h"

class WidgetsWindow : public wxFrame
{
public:
	WidgetsWindow();
	~WidgetsWindow();

public:

	std::vector<wxButton*> m_numButtons;

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
	wxTextCtrl* m_TextCtrl = nullptr;
	std::string m_preDecimal;
	std::string m_postDecimal;
	std::string m_preOpNum;
	std::string m_postOpNum;

	double m_total;
	double m_cur;
	int m_op;
	bool opExists = false;

	void updateDisplay();

	void onNumButton(wxCommandEvent&, int NUM);
	void OnNumClicked(wxCommandEvent& evt);
	void OnOperationClicked(wxCommandEvent& evt);
	void OnEqualClicked(wxCommandEvent& evt);
	void OnDeciClicked(wxCommandEvent&);
	void Clear(wxCommandEvent&);

	enum operation_type {
		OP_ADD,
		OP_SUB,
		OP_MUL,
		OP_DIV
	};

	static double performOperation(
		double left,
		double right,
		int op);
 
	wxDECLARE_EVENT_TABLE();
};

