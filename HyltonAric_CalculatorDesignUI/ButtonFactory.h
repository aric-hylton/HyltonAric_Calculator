#pragma once
#include <wx/wx.h>

class ButtonFactory
{
public:
	wxButton* CreateAddButton(wxWindow* callingWindow);
	wxButton* CreateSubButton(wxWindow* callingWindow);
	wxButton* CreateMulButton(wxWindow* callingWindow);
	wxButton* CreateDivButton(wxWindow* callingWindow);
	wxButton* CreateEqualsButton(wxWindow* callingWindow);

	wxButton* CreateHexButton(wxWindow* callingWindow);
	wxButton* CreateBinButton(wxWindow* callingWindow);
	wxButton* CreateModButton(wxWindow* callingWindow);
	wxButton* CreateCLSButton(wxWindow* callingWindow);

	wxButton* CreateSignButton(wxWindow* callingWindow);
	wxButton* CreateDecButton(wxWindow* callingWindow);

	std::vector<wxButton*> CreateNumButtons(wxWindow* callingWindow, std::vector<wxButton*> buttons);



public:

};

