/* Позволяет находить, открывать и закрывать указанный файл в указанной директории */
#pragma once
#include <string.h>
#include <cstdio>
#include <windows.h>

class transferFile
{
protected:
	char* name;										//Имя файла относительно текущей директории
	char* folder;									//Текущая директория
	char* fullpath;									//Полное имя
	int length = 0;									//Размер в байтах
	FILE* file;										//Файловый указатель
	char* buffer;									//Буфер для считывания пакета данных
public:
	transferFile(char* stringName, char* stringFolder);
	virtual bool open()=0;							//Открытие файла
	bool close();									//Закрытие файла
	char* getName() { return name; }				//Имя
	int getLen() { return length; }					//Размер
	~transferFile();
};