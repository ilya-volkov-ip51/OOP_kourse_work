/* ������� ������ ���� ������ � �������� ����������, ������� �������� ������ */
#pragma once
#include <windows.h>

class fileList
{
	char** filenames;											//������ ���� ������ � �� ����������� ������
	WIN32_FIND_DATAW* fileinfos;								//��������� �� ���������� ����� (������� �������������)
	int count = 0;												//���-�� ��������� ������
	char* directory;											//���������� ������
	void searchFiles(WCHAR* p);									//����������� ����� ������ �� ������ �������� �������
	void addFile(WCHAR* p, WIN32_FIND_DATAW info);				//���������� ���������� �����
public:
	fileList(char* dir);
	int createArray(char*** arr, WIN32_FIND_DATAW** infos);		//������� �������� ������ (��� � �������������� ������) � �� �������
	~fileList();
};
