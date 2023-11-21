#include "loginForm.h"
#include "dashboardForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SRMS::loginForm loginForm;

	loginForm.ShowDialog();
	User^ user = loginForm.user;

	if (user != nullptr) {
		SRMS::dashboardForm dashboardForm(user);
		Application::Run(% dashboardForm);
	}
	else {
		MessageBox::Show("No user found with username and password provided", "User Not Found", MessageBoxButtons::OK);
	}

}