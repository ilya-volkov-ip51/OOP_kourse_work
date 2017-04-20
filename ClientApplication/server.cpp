#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "server.h"
#include "fileList.h"
#define BUF 1024

int response(char* myfolder, SOCKET s1, sendFile** file) {
	char RecvBuffer[BUF];
	char MsgText[BUF];
	int err;
	err = recv(s1, (char *)&RecvBuffer, sizeof(RecvBuffer), 0);
	if (strcmp(RecvBuffer, "NAME") == 0) {
		strcpy(MsgText, (*file)->getName());
		err = send(s1, (char *)&MsgText, sizeof(MsgText), MSG_DONTROUTE);
	}
	else if (strcmp(RecvBuffer, "LEN") == 0) {
		char len[40];
		_itoa((*file)->getLen(), len, 10);
		strcpy(MsgText, len);
		err = send(s1, (char *)&MsgText, sizeof(MsgText), MSG_DONTROUTE);
	}
	else if (strcmp(RecvBuffer, "OK") == 0) {
		err = send(s1, (*file)->getBuf(), BUF, MSG_DONTROUTE);
		if ((*file)->getLen() <= 0) {
			(*file)->close();
		}
	}
	else if (strcmp(RecvBuffer, "PARAM") == 0) {
		err = send(s1, (char *)&(*file)->getParam(), sizeof(WIN32_FIND_DATAW), MSG_DONTROUTE);
		if (err == SOCKET_ERROR) return err;
		//printf("TRANSFER COMPLETE!\n");
		delete (*file);
	}
	else if (strcmp(RecvBuffer, "LIST") == 0) {
		fileList* list = new fileList(myfolder);
		char** names;
		WIN32_FIND_DATAW* infos;
		int num = list->createArray(&names, &infos);
		char n[40];
		_itoa(num, n, 10);
		strcpy(MsgText, n);
		err = send(s1, (char *)&MsgText, sizeof(MsgText), MSG_DONTROUTE);
		if (err == SOCKET_ERROR) return err;
		for (int i = 0; i < num; i++)
		{
			err = recv(s1, (char *)&RecvBuffer, sizeof(RecvBuffer), 0);
			if (err == SOCKET_ERROR) return err;
			strcpy(MsgText, names[i]);
			err = send(s1, (char *)&MsgText, sizeof(MsgText), MSG_DONTROUTE);
			if (err == SOCKET_ERROR) return err;
			err = recv(s1, (char *)&RecvBuffer, sizeof(RecvBuffer), 0);
			if (err == SOCKET_ERROR) return err;
			err = send(s1, (char *)&infos[i], sizeof(WIN32_FIND_DATAW), MSG_DONTROUTE);
			if (err == SOCKET_ERROR) return err;
		}
		printf("LIST SENDED!\n");
		delete names;
		delete infos;
		delete list;
	}
	else {
		(*file) = new sendFile(RecvBuffer, myfolder);
		if ((*file)->open() == false)
			strcpy(MsgText, "ERROR");
		else
			strcpy(MsgText, "OK");
		err = send(s1, (char *)&MsgText, sizeof(MsgText), MSG_DONTROUTE);
	}
	return err;
}
