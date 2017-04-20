/* ��������� ��������, ��������� � ��������� ��������� ���� � ��������� ���������� */
#pragma once
#include <string.h>
#include <cstdio>
#include <windows.h>

class transferFile
{
protected:
	char* name;										//��� ����� ������������ ������� ����������
	char* folder;									//������� ����������
	char* fullpath;									//������ ���
	int length = 0;									//������ � ������
	FILE* file;										//�������� ���������
	char* buffer;									//����� ��� ���������� ������ ������
public:
	transferFile(char* stringName, char* stringFolder);
	virtual bool open()=0;							//�������� �����
	bool close();									//�������� �����
	char* getName() { return name; }				//���
	int getLen() { return length; }					//������
	~transferFile();
};