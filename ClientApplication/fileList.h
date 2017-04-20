/* Создает список всех файлов в заданной директории, включая свойства файлов */
#pragma once
#include <windows.h>

class fileList
{
	char** filenames;											//Список имен файлов с их абсолютными путями
	WIN32_FIND_DATAW* fileinfos;								//Структура со свойствами файла (индексы соответствуют)
	int count = 0;												//Кол-во найденных файлов
	char* directory;											//Директория поиска
	void searchFiles(WCHAR* p);									//Рекурсивный поиск файлов по дереву файловой системы
	void addFile(WCHAR* p, WIN32_FIND_DATAW info);				//Добавление найденного файла
public:
	fileList(char* dir);
	int createArray(char*** arr, WIN32_FIND_DATAW** infos);		//Возврат массивов файлов (уже с относительными путями) и их свойств
	~fileList();
};
