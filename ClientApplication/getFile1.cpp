#define _CRT_SECURE_NO_WARNINGS
#include "getFile.h"
#include <io.h>
#include <direct.h>
#define BUF 1024

getFile::getFile(char* stringName, char* stringFolder, int length) : transferFile(stringName, stringFolder)
{
	localfolder = new char[strlen(fullpath) + 1];
	strcpy(localfolder, fullpath);

	/* Создание файла */
	absolutePath();
	createDirectory();
	fopen_s(&file, fullpath, "wb");
	if (file == NULL) {
		//perror("Creating failed");
		return;
	}
	fclose(file);

	this->length = length;
	file = NULL;
}

getFile::~getFile()
{
	delete[] localfolder;
}

void getFile::absolutePath() {
	char* tmp = strrchr(fullpath, '/') + 1;									//имя файла без относительного пути

	/* Удаление подстроки */
	char* p = 0, *p1 = 0;
	size_t size = strlen(tmp);
	for (; p = strstr(localfolder, tmp); )
	{
		p1 = p + size;
		while (*p++ = *p1++);
	}
}

bool getFile::createDirectory() {
	while (_mkdir(localfolder) == -1) {
		int k = strlen(localfolder);
		char* temp = new char[k + 1];
		strcpy(temp, localfolder);
		while (_mkdir(temp) != 0) {
			while (temp[--k] != '/')
			{
				if (k <= 1) return false;
				temp[k] = NULL;
			}
		}
		delete[] temp;
	}
	return true;
}

bool getFile::open() {
	fopen_s(&file, fullpath, "ab");
	if (file == NULL) return false;						//Файл не найден

	return true;
}

bool getFile::writeBuf(char* buffer) {
	if (file == NULL || length <= 0) return false;				// Файл не открыт либо записан полностью

	if (length >= BUF) {
		fwrite(buffer, BUF, 1, file);
		length -= BUF;
	}
	else {
		fwrite(buffer, length, 1, file);
		length = 0;
	}
	return true;
}

bool getFile::del() {
	if (file == NULL || length <= 0) return false;				// Файл не открыт либо записан полностью

	close();
	if (remove(fullpath)) return false;
	return true;
}

void getFile::setParam(WIN32_FIND_DATAW param) {
	OFSTRUCT of;
	HANDLE hFile = (HANDLE)OpenFile(fullpath, &of, OF_READWRITE);
	SetFileTime(hFile, &param.ftCreationTime, &param.ftLastAccessTime, &param.ftLastWriteTime);
	CloseHandle(hFile);
}
