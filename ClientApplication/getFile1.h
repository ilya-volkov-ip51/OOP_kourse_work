/* Позволяет записывать файл по частям и задавать некоторые его свойства */
#pragma once
#include "transferFile.h"

class getFile : public transferFile
{
	char* localfolder;								//Абсолютный путь
	bool createDirectory();							//Создание промежуточных директорий
	void absolutePath();							//Абсолютный путь
public:
	getFile(char* stringName, char* stringFolder, int length);
	bool open();									//Открытие файла
	bool del();										//Удаление файла
	bool writeBuf(char* buffer);					//Запись очередного пакета
	void setParam(WIN32_FIND_DATAW param);			// Установка параметвов файла
	~getFile();
};

