/* ��������� ���������� ���� �� ������ � �������� ��������� ��� �������� */
#pragma once
#include "transferFile.h"

class getFile : public transferFile
{
	char* localfolder;								//���������� ����
	bool createDirectory();							//�������� ������������� ����������
	void absolutePath();							//���������� ����
public:
	getFile(char* stringName, char* stringFolder, int length);
	bool open();									//�������� �����
	bool del();										//�������� �����
	bool writeBuf(char* buffer);					//������ ���������� ������
	void setParam(WIN32_FIND_DATAW param);			// ��������� ���������� �����
	~getFile();
};

