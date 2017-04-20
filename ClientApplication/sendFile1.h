/* Позволяет считывать файл по частям и считывать его свойства */
#pragma once
#include "transferFile.h"

class sendFile: public transferFile
{
public:
	sendFile(char* stringName, char* stringFolder);
	char* getBuf();									//Считывание очередного пакета
	bool open();									//Открытие файла
	WIN32_FIND_DATAW getParam();					//Параметры файла
	~sendFile();
};

