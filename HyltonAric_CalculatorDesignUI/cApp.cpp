#include "cApp.h"

wxIMPLEMENT_APP(cApp);

bool cApp::OnInit() {
	window = new WidgetsWindow();
	window->Show();
	return true;
}