/* ��������� ������� �������������� ���-�� ����� */
#pragma once
class stringArray
{
	char** arr;								//������ �����
	int count = 0;							//���-�� �����
public:
	stringArray();
	void add(char* string);					//���������� ������
	int getCount() { return count; };		//���-�� �����
	char* operator[](int i);				//������ �� �������
	~stringArray();
};

