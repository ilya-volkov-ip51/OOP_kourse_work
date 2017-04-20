/* Позволяет хранить неограниченное кол-во строк */
#pragma once
class stringArray
{
	char** arr;								//Массив строк
	int count = 0;							//Кол-во строк
public:
	stringArray();
	void add(char* string);					//Добавление строки
	int getCount() { return count; };		//Кол-во строк
	char* operator[](int i);				//Доступ по индексу
	~stringArray();
};

