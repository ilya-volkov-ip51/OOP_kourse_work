#define _CRT_SECURE_NO_WARNINGS
#include "sendFile.h"
#include <io.h>
#include <string.h>
#define BUF 1024

sendFile::sendFile(char* stringName, char* stringFolder): transferFile(stringName, stringFolder)
{
	/* Определение размера файла */
	fopen_s(&file, fullpath, "rb");
	if (file == NULL) {
		//perror("Opening failed");
		return;
	}
	length = _filelength(_fileno(file));
	//if (length == -1L) perror("filelength failed");	//Длина не определена	
	fclose(file);
}

sendFile::~sendFile()
{
}

bool sendFile::open() {
	fopen_s(&file, fullpath, "rb");
	if (file == NULL) return false;						//Файл не найден

	return true;
}

char* sendFile::getBuf() {
	if (file == NULL || length <= 0) return NULL;		//Файл не открыт либо считан полностью

	if (buffer != NULL) delete[] buffer;
	buffer = new char[BUF];
	if (length >= BUF) {
		fread(buffer, BUF, 1, file);
		length -= BUF;
	}
	else {
		fread(buffer, length, 1, file);
		length = 0;
	}
	return buffer;
}

WIN32_FIND_DATAW sendFile::getParam() {
	WIN32_FIND_DATAW search;
	HANDLE hFind;
	int nChars = MultiByteToWideChar(CP_ACP, 0, fullpath, -1, NULL, 0);
	WCHAR* tmp = new WCHAR[nChars];
	MultiByteToWideChar(CP_ACP, 0, fullpath, -1, (LPWSTR)tmp, nChars);
	hFind = FindFirstFileW(tmp, &search);
	delete[] tmp;
	return search;
}