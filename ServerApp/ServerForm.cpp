#include "ServerForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ServerApp::ServerForm form;  //нужно указать имя своего проекта (а не test_project)
	Application::Run(%form);
}

