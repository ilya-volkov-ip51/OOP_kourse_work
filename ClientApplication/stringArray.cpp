#define _CRT_SECURE_NO_WARNINGS
#include "stringArray.h"
#include <string.h>


stringArray::stringArray()
{
	arr = new char*[count];
}

void stringArray::add(char* string) {
	char** temp = new char*[count + 1];
	for (int i = 0; i < count; i++) {
		temp[i] = new char[strlen(arr[i]) + 1];
		strcpy(temp[i], arr[i]);
	}
	temp[count] = new char[strlen(string) + 1];
	strcpy(temp[count], string);
	for (int i = 0; i < count; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = temp;
	count++;
}

char* stringArray::operator[](int i) {
	char* tmp = new char[strlen(arr[i]) + 1];
	strcpy(tmp, arr[i]);
	return tmp;
}


stringArray::~stringArray()
{
	for (int i = 0; i < count; i++) delete[] arr[i];
	delete[] arr;
}
