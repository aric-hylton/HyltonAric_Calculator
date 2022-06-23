#include "ButtonFactory.h"

std::vector<wxButton*> ButtonFactory::CreateNumButtons(wxWindow* callingWindow, std::vector<wxButton*> buttons) {
	
	wxSize buttonSize(100, 60);

	// create 1-9
	int xPos = 10,
		yPos = 200;

	for (int num = 1; num < 10; ++num) {
		buttons[num] = new wxButton(callingWindow, num, std::to_string(num), \
			wxPoint(xPos, yPos), buttonSize);
		xPos += 110;
		if (num % 3 == 0) {
			yPos += 70;
			xPos = 10;
		}
	}
	buttons[0] = new wxButton(callingWindow, 0, "0", wxPoint(120, 410), buttonSize);

	return buttons;
}

/* --------------------------------------------------------------------- */

wxButton* ButtonFactory::CreateAddButton(wxWindow* callingWindow) {
	wxButton* add = new wxButton(callingWindow, 1024);
	add->SetLabel("+");
	add->SetPosition(wxPoint(340, 340));
	add->SetSize(100, 60);
	return add;
}

wxButton* ButtonFactory::CreateSubButton(wxWindow* callingWindow) {
	wxButton* sub = new wxButton(callingWindow, 1025);
	sub->SetLabel("-");
	sub->SetPosition(wxPoint(340, 270));
	sub->SetSize(100, 60);
	return sub;
}

wxButton* ButtonFactory::CreateMulButton(wxWindow* callingWindow) {
	wxButton* mul = new wxButton(callingWindow, 1026);
	mul->SetLabel("*");
	mul->SetPosition(wxPoint(340, 200));
	mul->SetSize(100, 60);
	return mul;
}

wxButton* ButtonFactory::CreateDivButton(wxWindow* callingWindow) {
	wxButton* div = new wxButton(callingWindow, 1027);
	div->SetLabel("/");
	div->SetPosition(wxPoint(340, 130));
	div->SetSize(100, 60);
	return div;
}

wxButton* ButtonFactory::CreateEqualsButton(wxWindow* callingWindow) {
	wxButton* equals = new wxButton(callingWindow, 1032);
	equals->SetLabel("=");
	equals->SetPosition(wxPoint(340, 410));
	equals->SetSize(100, 60);
	return equals;
}
/* --------------------------------------------------------------------- */

wxButton* ButtonFactory::CreateHexButton(wxWindow* callingWindow) {
	wxButton* hex = new wxButton(callingWindow, 1029);
	hex->SetLabel("hex");
	hex->SetPosition(wxPoint(92, 130));
	hex->SetSize(75, 60);
	return hex;
}

wxButton* ButtonFactory::CreateBinButton(wxWindow* callingWindow) {
	wxButton* bin = new wxButton(callingWindow, 1030);
	bin->SetLabel("bin");
	bin->SetPosition(wxPoint(174, 130));
	bin->SetSize(75, 60);
	return bin;
}

wxButton* ButtonFactory::CreateModButton(wxWindow* callingWindow) {
	wxButton* mod = new wxButton(callingWindow, 1028);
	mod->SetLabel("mod");
	mod->SetPosition(wxPoint(255, 130));
	mod->SetSize(75, 60);
	return mod;
}

wxButton* ButtonFactory::CreateCLSButton(wxWindow* callingWindow) {
	wxButton* cls = new wxButton(callingWindow, 1031);
	cls->SetLabel("cls");
	cls->SetPosition(wxPoint(10, 130));
	cls->SetSize(75, 60);
	return cls;
}

/* --------------------------------------------------------------------- */

wxButton* ButtonFactory::CreateSignButton(wxWindow* callingWindow) {
	wxButton* sign = new wxButton(callingWindow, 11);
	sign->SetLabel("+/-");
	sign->SetPosition(wxPoint(10, 410));
	sign->SetSize(100, 60);
	return sign;
}

wxButton* ButtonFactory::CreateDecButton(wxWindow* callingWindow) {
	wxButton* dec = new wxButton(callingWindow, 10);
	dec->SetLabel(".");
	dec->SetPosition(wxPoint(230, 410));
	dec->SetSize(100, 60);
	return dec;
}