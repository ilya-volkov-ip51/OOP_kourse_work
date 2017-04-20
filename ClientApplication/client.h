/* Набор функций для приема файлов */
#pragma once
#include "stringArray.h"
#include "Winsock2.h"
#include <windows.h>

int recieveFile(char* filename, char* myfolder, SOCKET s);						//Получить файл
int recieveList(stringArray* diffList, char* myfolder, SOCKET s);				//Загрузить список файлов
int getFiles(SOCKET s, char*** names, WIN32_FIND_DATAW** infos, int* number);	//Получить список файлов
void diffFileList(stringArray* diffList, char* myfolder, SOCKET s);				//Разница файлов (отсутствующие и созданные позже)