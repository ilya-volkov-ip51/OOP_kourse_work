#pragma once
#include "About.h"
#include "client.h"
#include <cstdio>
#include <iostream>

char errMsg[100];													//Текст сообщения об ошибке
char path[260];
int err;
WSADATA WsaData;
SOCKET clientSock;
SOCKADDR_IN clientAddr;
HANDLE clientThread;

namespace ClientApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	DWORD WINAPI clientStart(LPVOID lpParam);

	/// <summary>
	/// Summary for ClientForm
	/// </summary>
	public ref class ClientForm : public System::Windows::Forms::Form
	{
	public:
		ClientForm(void)
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
		~ClientForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ClientForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Root directory:";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Window;
			this->textBox1->Location = System::Drawing::Point(12, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(179, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(197, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Browse...";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ClientForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"IP adress of server:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 73);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(179, 20);
			this->textBox2->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 110);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(124, 32);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Connect to server";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ClientForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(148, 110);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(124, 32);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Disconnect from server";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(197, 184);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 7;
			this->button4->Text = L"About";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &ClientForm::button4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 189);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"State:";
			// 
			// ClientForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 211);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"ClientForm";
			this->Text = L"Synchronizer Client";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ClientForm::ClientForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &ClientForm::ClientForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// Вызов меню выбора папки
	public: void ChooseFolder()
	{
		if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			textBox1->Text = folderBrowserDialog1->SelectedPath;
		}
	}
	// Кнопка выбора папки
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		ChooseFolder();
	}
	// Кнопка вызома описания
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		ClientApplication::About form;
		form.ShowDialog();
	}
	//Загрузка формы
	private: System::Void ClientForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//инициализация процесса библиотеки
		int err = WSAStartup(0x0101, &WsaData);
		if (err == SOCKET_ERROR)
		{
			sprintf(errMsg, "WSAStartup failed: %ld\n", GetLastError());
			String^ msg = gcnew String(errMsg);
			MessageBox::Show(msg, "Error");
			Application::Exit();
		}
		
	}
	private: System::Void ClientForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		//TerminateThread(clientThread, 0);
		
		//вынос мусора
		//WSACleanup();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		setlocale(LC_ALL,"rus");
		//создание сокета
		clientSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		//задаем параметры для сокета
		clientAddr.sin_family = AF_INET;
		clientAddr.sin_port = htons(8080);
		clientAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");				//ip адрес подключения
																				//соединяемся с сервером
		err = connect(clientSock, (struct sockaddr *)&clientAddr, sizeof(struct sockaddr));
		if (err == SOCKET_ERROR)
		{
			sprintf(errMsg, "connect() failed: %ld\n", GetLastError());
			String^ msg = gcnew String(errMsg);
			MessageBox::Show(msg, "Error");
			closesocket(clientSock);
			WSACleanup();
			//system("pause");
			Application::Exit();
		}
		//printf("Connection successfull!\n");

		//printf("\nDifferent files:\n");
		stringArray* fileDiff = new stringArray();
		diffFileList(fileDiff, "C:/Users/User/Desktop/folder1", clientSock);
		int count = recieveList(fileDiff, "C:/Users/User/Desktop/folder1", clientSock);
		sprintf(errMsg, "Transfered: %d", fileDiff->getCount());
		String^ msg = gcnew String(errMsg);
		MessageBox::Show(msg, "Error");
		delete fileDiff;
		//закрытие сокета
		closesocket(clientSock);
	}
};
DWORD WINAPI clientStart(LPVOID lpParam) {
	//создание сокета
	clientSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//задаем параметры для сокета
	SOCKADDR_IN clientAddr;
	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(8080);
	clientAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");				//ip адрес подключения
																			//соединяемся с сервером
	err = connect(clientSock, (struct sockaddr *)&clientAddr, sizeof(struct sockaddr));
	if (err == SOCKET_ERROR)
	{
		sprintf(errMsg, "connect() failed: %ld\n", GetLastError());
		String^ msg = gcnew String(errMsg);
		MessageBox::Show(msg, "Error");
		closesocket(clientSock);
		WSACleanup();
		//system("pause");
		Application::Exit();
	}
	//printf("Connection successfull!\n");

	//printf("\nDifferent files:\n");
	stringArray* fileDiff = new stringArray();
	diffFileList(fileDiff, "C:/Users/User/Desktop/folder1", clientSock);
	int count = recieveList(fileDiff, "C:/Users/User/Desktop/folder1", clientSock);
	sprintf(errMsg, "Transfered: %d", fileDiff->getCount());
	String^ msg = gcnew String(errMsg);
	MessageBox::Show(msg, "Error");
	delete fileDiff;
	//закрытие сокета
	closesocket(clientSock);
	return 0;
}
}
