/* ��������� ��������� ���� �� ������ � ��������� ��� �������� */
#pragma once
#include "transferFile.h"

class sendFile: public transferFile
{
public:
	sendFile(char* stringName, char* stringFolder);
	char* getBuf();									//���������� ���������� ������
	bool open();									//�������� �����
	WIN32_FIND_DATAW getParam();					//��������� �����
	~sendFile();
};

