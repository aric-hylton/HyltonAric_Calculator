#include "ButtonFactory.h"

wxButton* ButtonFactory::CreateAddButton(wxWindow* callingWindow) {
	wxButton* add = new wxButton(callingWindow, 1024, "+", wxPoint(340, 270), wxSize(100, 60));
	return add;
}

wxButton* ButtonFactory::CreateSubButton(wxWindow* callingWindow) {
	wxButton* sub = new wxButton(callingWindow, 1025, "-", wxPoint(340, 340), wxSize(100, 60));
	return sub;
}

wxButton* ButtonFactory::CreateMulButton(wxWindow* callingWindow) {
	wxButton* mul = new wxButton(callingWindow, 1026, "*", wxPoint(340, 200), wxSize(100, 60));
	return mul;
}

wxButton* ButtonFactory::CreateDivButton(wxWindow* callingWindow) {
	wxButton* div = new wxButton(callingWindow, 1027, "/", wxPoint(340, 130), wxSize(100, 60));
	return div;
}

wxButton* ButtonFactory::CreateEqualsButton(wxWindow* callingWindow) {
	wxButton* equals = new wxButton(callingWindow, 1032, "=", wxPoint(340, 410), wxSize(100, 60));
	return equals;
}
/* --------------------------------------------------------------------- */

wxButton* ButtonFactory::CreateHexButton(wxWindow* callingWindow) {
	wxButton* hex = new wxButton(callingWindow, 1029, "hex", wxPoint(92, 130), wxSize(75, 60));
	return hex;
}

wxButton* ButtonFactory::CreateBinButton(wxWindow* callingWindow) {
	wxButton* bin = new wxButton(callingWindow, 1030, "bin", wxPoint(174, 130), wxSize(75, 60));
	return bin;
}

wxButton* ButtonFactory::CreateModButton(wxWindow* callingWindow) {
	wxButton* mod = new wxButton(callingWindow, 1028, "mod", wxPoint(255, 130), wxSize(75, 60));
	return mod;
}

wxButton* ButtonFactory::CreateCLSButton(wxWindow* callingWindow) {
	wxButton* cls = new wxButton(callingWindow, 1031, "c", wxPoint(10, 130), wxSize(75, 60));
	return cls;
}

/* --------------------------------------------------------------------- */

wxButton* ButtonFactory::CreateSignButton(wxWindow* callingWindow) {
	wxButton* sign = new wxButton(callingWindow, 11, "+/-", wxPoint(10, 410), wxSize(100, 60));
	return sign;
}

wxButton* ButtonFactory::CreateDecButton(wxWindow* callingWindow) {
	wxButton* dec = new wxButton(callingWindow, 10, ".", wxPoint(230, 410), wxSize(100, 60));
	return dec;
}