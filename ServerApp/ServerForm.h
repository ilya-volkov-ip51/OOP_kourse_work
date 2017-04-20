#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "../ClientApplication/server.h"
#include "About1.h"

/*char errMsg[100];													//Текст сообщения об ошибке
char path[260];
int err;
WSADATA WsaData;
SOCKET serverSock;
SOCKADDR_IN serverAddr;
HANDLE serverThread;
SOCKET s1;*/

void replace(char* str, char old_value, char new_value);			//Замена символов в строке

namespace ServerApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//DWORD WINAPI serverStart(LPVOID lpParam);
	/// <summary>
	/// Summary for ServerForm
	/// </summary>
	public ref class ServerForm : public System::Windows::Forms::Form
	{
	public:
		ServerForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ServerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ServerForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Window;
			this->textBox1->Location = System::Drawing::Point(12, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(179, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Root directory:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(197, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Browse...";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ServerForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 67);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(124, 32);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Server start";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ServerForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(148, 67);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(124, 32);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Server stop";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ServerForm::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 139);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"State:";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(197, 134);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 6;
			this->button4->Text = L"About";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &ServerForm::button4_Click);
			// 
			// ServerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 161);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"ServerForm";
			this->Text = L"Synchronizer Server";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ServerForm::ServerForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &ServerForm::ServerForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: void ChooseFolder()
	{
		if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			textBox1->Text = folderBrowserDialog1->SelectedPath;
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		/*ChooseFolder();*/
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		/*ServerApp::About1 form;  //нужно указать имя своего проекта (а не test_project)
		form.ShowDialog();*/
	}
	private: System::Void ServerForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//инициализация процесса библиотеки

		/*err = WSAStartup(0x0101, &WsaData);
		if (err == SOCKET_ERROR)
		{
			sprintf(errMsg, "WSAStartup failed: %ld\n", GetLastError());
			String^ msg = gcnew String(errMsg);
			MessageBox::Show(msg, "Error");
			Application::Exit();
		}
		//создание сокета
		serverSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		//задаем параметры для сокета
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = htons(8080);
		serverAddr.sin_addr.s_addr = INADDR_ANY;
		//serverAddr.sin_addr.S_un.S_addr = inet_addr("192.168.1.231");
		//подключение сокета к коммуникационной среде
		err = bind(serverSock, (LPSOCKADDR)&serverAddr, sizeof(serverAddr));
		if (err == -1)
		{
			sprintf(errMsg, "Bind socket failed: %ld\n", GetLastError());
			String^ msg = gcnew String(errMsg);
			MessageBox::Show(msg, "Error");
			Application::Exit();
		}*/
	}
	private: System::Void ServerForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		/*//закрытие потока
		TerminateThread(serverThread, 0);
		//закрытие сокета
		closesocket(serverSock);
		//вынос мусора
		WSACleanup();*/
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		/*if (String::IsNullOrEmpty(textBox1->Text)) {
			String^ msg;
			sprintf(errMsg, "Directory hasn`t been set!");
			msg = gcnew String(errMsg);
			MessageBox::Show(msg, "Error");
			return;
		}
		sprintf(path, "%s",textBox1->Text);
		replace(path, '\\','/');
		serverThread= CreateThread(NULL,0, serverStart,	NULL,0,NULL);*/

		//инициализация процесса библиотеки
		WSADATA WsaData;
		int err = WSAStartup(0x0101, &WsaData);
		if (err == SOCKET_ERROR)
		{
			printf("WSAStartup() failed: %ld\n", GetLastError());
		}
		//создание сокета
		SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		//задаем параметры для сокета
		SOCKADDR_IN sin;
		sin.sin_family = AF_INET;
		sin.sin_port = htons(8080);
		sin.sin_addr.s_addr = INADDR_ANY;
		//sin.sin_addr.S_un.S_addr = inet_addr("192.168.56.1");
		//подключение сокета к коммуникационной среде
		err = bind(s, (LPSOCKADDR)&sin, sizeof(sin));
		if (err == -1)
		{
			printf("bind() failed: %ld\n", GetLastError());
			system("pause");
		}
		//желаем ожидать запросы
		err = listen(s, SOMAXCONN);
		if (err == -1)
		{
			printf("listen() failed: %ld\n", GetLastError());
		}

		//еще 1 сокет...
		SOCKADDR_IN from;
		int fromlen = sizeof(from);
		//прием запросов от клиентов на установление связи
		SOCKET s1;

		while (true) {
			printf("waiting for connection...\n");
			sendFile* file;
			s1 = accept(s, (struct sockaddr*)&from, &fromlen);
			//ip адрес и порт удаленного компа
			printf("accepted connection from %s, port %d\n", inet_ntoa(from.sin_addr), htons(from.sin_port));
			while (true) {
				err = response("C:/Users/User/Desktop/folder", s1, &file);
				if (err == SOCKET_ERROR)
				{
					if (file != NULL) {
						printf("Transmittion ended!\n");
						delete file;
					}
					break;
				}
			}
		}
		//закрытие сокета
		closesocket(s);
		//вынос мусора
		WSACleanup();
		system("pause");







	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		/*TerminateThread(serverThread, 0);
		closesocket(s1);*/
	}
};

/*	DWORD WINAPI serverStart(LPVOID lpParam) {
		String^ msg;
		//желаем ожидать запросы
		err = listen(serverSock, SOMAXCONN);
		if (err == -1)
		{
			sprintf(errMsg, "Listen failed: %ld\n", GetLastError());
			msg = gcnew String(errMsg);
			MessageBox::Show(msg, "Error");
			Application::Exit();
		}
		//еще 1 сокет...
		SOCKADDR_IN from;
		int fromlen = sizeof(from);
		//прием запросов от клиентов на установление связи
		while (true) {
			sprintf(errMsg, "Waiting for connection...");
			msg = gcnew String(errMsg);
			MessageBox::Show(msg, "Info");
			sendFile* file = NULL;
			s1 = accept(serverSock, (struct sockaddr*)&from, &fromlen);
			//ip адрес и порт удаленного компа
			sprintf(errMsg, "accepted connection from %s, port %d\n", inet_ntoa(from.sin_addr), htons(from.sin_port));
			msg = gcnew String(errMsg);
			MessageBox::Show(msg, "Info");
			while (true) {
				err = response("C:/Users/User/Desktop/folder", s1, &file);
				if (err == SOCKET_ERROR)
				{
					if (file != NULL) {
						//cout << "Transmittion ended!" << endl;
						delete file;
					}
					break;
				}
			}
		}
		return 0;
	}*/
}

void replace(char* str, char old_value, char new_value) {
	for (; *str; ++str)
		if (*str == old_value)
			*str = new_value;
}