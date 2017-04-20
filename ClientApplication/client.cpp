#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "client.h"
#include "fileList.h"
#include "getFile.h"
#define BUF 1024


int getFiles(SOCKET s, char*** names, WIN32_FIND_DATAW** infos, int* number) {
	char RecvBuffer[BUF];
	char MsgText[BUF];
	strcpy(MsgText, "LIST");
	int err = send(s, (char *)&MsgText, sizeof(MsgText), MSG_DONTROUTE);
	if (err == SOCKET_ERROR) return err;
	err = recv(s, (char *)&RecvBuffer, sizeof(RecvBuffer), 0);
	if (err == SOCKET_ERROR) return err;
	(*number) = atoi(RecvBuffer);
	(*names) = new char*[(*number)];
	(*infos) = new WIN32_FIND_DATAW[(*number)];
	strcpy(MsgText, "OK");
	for (int i = 0; i < (*number); i++) {

		err = send(s, (char *)&MsgText, sizeof(MsgText), MSG_DONTROUTE);
		if (err == SOCKET_ERROR) return err;

		err = recv(s, (char *)&RecvBuffer, sizeof(RecvBuffer), 0);
		if (err == SOCKET_ERROR) return err;

		(*names)[i] = new char[strlen(RecvBuffer) + 1];
		strcpy((*names)[i], RecvBuffer);
		err = send(s, (char *)&MsgText, sizeof(MsgText), MSG_DONTROUTE);
		if (err == SOCKET_ERROR) return err;

		err = recv(s, (char *)&(*infos)[i], sizeof(WIN32_FIND_DATAW), 0);
		if (err == SOCKET_ERROR) return err;
	}
	return err;
}

int recieveList(stringArray* diffList, char* myfolder, SOCKET s) {
	int number = 0;
	int err;
	for (int i = 0; i < diffList->getCount(); i++) {
		err = recieveFile((*diffList)[i], myfolder, s);
		if (err == SOCKET_ERROR)
		{
			//printf("Transfer failed: %s\n", (*diffList)[i]);
		}
		else
		{
			//printf("Transfer successfull: %s\n", (*diffList)[i]);
			number++;
		}
	}
	return number;
}

int recieveFile(char* filename, char* myfolder, SOCKET s) {
	char RecvBuffer[BUF];
	char MsgText[BUF];
	//Проверка наличия файла
	strcpy(MsgText, filename);
	int err = send(s, (char *)&MsgText, sizeof(MsgText), MSG_DONTROUTE);
	if (err == SOCKET_ERROR)
	{
		return err;
	}
	err = recv(s, (char *)&RecvBuffer, sizeof(RecvBuffer), 0);
	if (strcmp(RecvBuffer, "OK") != 0)
	{
		return err;
	}
	// Отправляем запрос на имя
	strcpy(MsgText, "NAME");
	err = send(s, (char *)&MsgText, sizeof(MsgText), MSG_DONTROUTE);
	if (err == SOCKET_ERROR)
	{
		return err;
	}
	err = recv(s, (char *)&RecvBuffer, sizeof(RecvBuffer), 0);
	if (err == SOCKET_ERROR)
	{
		return err;
	}
	char name[BUF];
	strcpy(name, RecvBuffer);

	// Отправляем запрос длину
	strcpy(MsgText, "LEN");
	err = send(s, (char *)&MsgText, sizeof(MsgText), MSG_DONTROUTE);
	if (err == SOCKET_ERROR)
	{
		return err;
	}
	err = recv(s, (char *)&RecvBuffer, sizeof(RecvBuffer), 0);
	if (err == SOCKET_ERROR)
	{
		return err;
	}
	int len = atoi(RecvBuffer);
	getFile* file = new getFile(name, myfolder, len);

	//Отправляем запрос на получение пакетов
	if (file->open() == true) {
		strcpy(MsgText, "OK");
		while (file->getLen() > 0) {
			err = send(s, (char *)&MsgText, sizeof(MsgText), MSG_DONTROUTE);
			if (err == SOCKET_ERROR)
			{
				file->del();
				delete file;
				return err;
			}
			err = recv(s, (char *)&RecvBuffer, sizeof(RecvBuffer), 0);
			if (err == SOCKET_ERROR)
			{
				file->del();
				delete file;
				return err;
			}
			file->writeBuf(RecvBuffer);
		}
		file->close();
		/* Получение параметров файла */
		strcpy(MsgText, "PARAM");
		err = send(s, (char *)&MsgText, sizeof(MsgText), MSG_DONTROUTE);
		if (err == SOCKET_ERROR)
		{
			file->del();
			delete file;
			return err;
		}
		WIN32_FIND_DATAW parameter;
		err = recv(s, (char *)&parameter, sizeof(WIN32_FIND_DATAW), 0);
		if (err == SOCKET_ERROR)
		{
			file->del();
			delete file;
			return err;
		}
		file->setParam(parameter);
	}
	else {
		delete file;
		file->del();
		return err;
	}
	delete file;
	return 0;
}

void diffFileList(stringArray* diffList, char* myfolder, SOCKET s) {
	char** names;
	WIN32_FIND_DATAW* infos;
	int count;
	int err = getFiles(s, &names, &infos, &count);
	if (err == SOCKET_ERROR)
	{
		System::Windows::Forms::MessageBox::Show("Connection failed!\n");
		return;
	}
	fileList* list = new fileList(myfolder);
	char** myNames;
	WIN32_FIND_DATAW* myInfos;
	int myCount = list->createArray(&myNames, &myInfos);
	for (int i = 0; i < count; i++) {
		bool flag = false;
		for (int j = 0; j < myCount; j++) {
			if (strcmp(names[i], myNames[j]) == 0)
				if (CompareFileTime(&(infos[i].ftLastWriteTime), &(myInfos[j].ftLastWriteTime)) != 1)
					flag = true;
		}
		if (!flag) diffList->add(names[i]);
	}
	System::Windows::Forms::MessageBox::Show("Success!\n");
	return;
}