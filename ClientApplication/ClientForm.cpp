#include "ClientForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ClientApplication::ClientForm form;  //����� ������� ��� ������ ������� (� �� test_project)
	Application::Run(%form);
}

