#define _CRT_SECURE_NO_WARNINGS
#include "transferFile.h"

transferFile::transferFile(char* stringName, char* stringFolder)
{
	name = new char[strlen(stringName) + 1];
	strcpy(name, stringName);

	folder = new char[strlen(stringFolder) + 1];
	strcpy(folder, stringFolder);

	fullpath = new char[strlen(stringFolder) + strlen(stringName) + 2];
	strcpy(fullpath, stringFolder);
	strcat(fullpath, "/");
	strcat(fullpath, stringName);
}

transferFile::~transferFile()
{
	delete[] name;
	delete[] folder;
	delete[] fullpath;
}

bool transferFile::close() {
	if (file == nullptr) return false;						// Файл не открыт
	fclose(file);
	file = NULL;
	return true;
}