#define _CRT_SECURE_NO_WARNINGS
#include "fileList.h"
#include <iostream>
#include <string.h>
using namespace std;

fileList::fileList(char* dir)
{
	directory = new char[strlen(dir) + 3];
	strcpy(directory, dir);
	strcat(directory, "/*");
	int nChars = MultiByteToWideChar(CP_ACP, 0, directory, -1, NULL, 0);
	WCHAR* tmp = new WCHAR[nChars];
	MultiByteToWideChar(CP_ACP, 0, directory, -1, (LPWSTR)tmp, nChars);
	searchFiles(tmp);
	delete[] tmp;
}

void fileList::addFile(WCHAR* p, WIN32_FIND_DATAW info) {
	char** temp = new char*[count + 1];
	WIN32_FIND_DATAW* temp1 = new WIN32_FIND_DATAW[count + 1];
	for (int i = 0; i < count; i++) {
		temp[i] = new char[strlen(filenames[i]) + 1];
		temp1[i] = fileinfos[i];
		strcpy(temp[i], filenames[i]);
	}
	temp[count] = new char[wcslen(p) + 1];
	temp1[count] = info;
	sprintf(temp[count], "%ws", p);
	for (int i = 0; i < count; i++) {
		delete[] filenames[i];
	}
	delete[] filenames;
	delete[] fileinfos;
	fileinfos = temp1;
	filenames = temp;
	count++;
}

int fileList::createArray(char*** arr, WIN32_FIND_DATAW** infos) {
	(*arr) = new char*[count];
	(*infos) = new WIN32_FIND_DATAW[count];
	for (int i = 0; i < count; i++) {
		(*infos)[i] = fileinfos[i];
		(*arr)[i] = new char[strlen(filenames[i]) + 1];
		strcpy((*arr)[i], filenames[i]);

		/* Directory remove from arr[i] */
		char* p = 0, *p1 = 0;
		size_t size = strlen(directory);
		char* dirtmp = new char[size];
		strncpy(dirtmp, directory, size - 1);
		dirtmp[size - 1] = '\0';
		for (; p = strstr((*arr)[i], dirtmp); )
		{
			p1 = p + size - 1;
			while (*p++ = *p1++);
		}
		delete[] dirtmp;
	}
	return count;
}

void fileList::searchFiles(WCHAR* p) {
	WIN32_FIND_DATAW search;
	HANDLE hFind;
	hFind = FindFirstFileW(p, &search);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		//wcout << p << L" invalid" << endl;
	}
	else
	{
		do {
			if ((((search.dwFileAttributes)&FILE_ATTRIBUTE_DIRECTORY) != 0) && (wcscmp(search.cFileName, L".") != 0) && (wcscmp(search.cFileName, L"..") != 0))
			{
				if ((wcslen(p) + wcslen(search.cFileName) < MAX_PATH) && ((wcsstr(p, search.cFileName) != p + wcslen(p) - wcslen(search.cFileName) - 2) || (search.dwFileAttributes&FILE_ATTRIBUTE_SYSTEM == 0)))
				{
					WCHAR temp[MAX_PATH];
					wcscpy(temp, p);
					temp[wcslen(temp) - 1] = temp[wcslen(p)];
					wcscat(temp, search.cFileName);
					wcscat(temp, L"/*");
					searchFiles(temp);
				}
			}
			else
				if (((search.dwFileAttributes)&FILE_ATTRIBUTE_DIRECTORY) == 0)
				{
					if (wcslen(p) + wcslen(search.cFileName) < MAX_PATH)
					{
						WCHAR temp[MAX_PATH];
						wcscpy(temp, p);
						temp[wcslen(temp) - 1] = temp[wcslen(p)];
						wcscat(temp, search.cFileName);
						//wcout << temp;
						addFile(temp, search);
						if (((search.dwFileAttributes)&FILE_ATTRIBUTE_HIDDEN) != 0)
						{
							//wcout << L" -hidden";
						}
						//wcout << endl;
					}
				}
		} while (FindNextFileW(hFind, &search));
		FindClose(hFind);
	}
}

fileList::~fileList()
{
	delete[] directory;
	for (int i = 0; i < count; i++) {
		delete[] filenames[i];
	}
	delete[] filenames;
}
