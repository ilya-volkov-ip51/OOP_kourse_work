/* ����� ������� ��� ������ ������ */
#pragma once
#include "stringArray.h"
#include "Winsock2.h"
#include <windows.h>

int recieveFile(char* filename, char* myfolder, SOCKET s);						//�������� ����
int recieveList(stringArray* diffList, char* myfolder, SOCKET s);				//��������� ������ ������
int getFiles(SOCKET s, char*** names, WIN32_FIND_DATAW** infos, int* number);	//�������� ������ ������
void diffFileList(stringArray* diffList, char* myfolder, SOCKET s);				//������� ������ (������������� � ��������� �����)