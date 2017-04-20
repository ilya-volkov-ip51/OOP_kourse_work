#pragma once
#include "Winsock2.h"
#include "sendFile.h"

int response(char* myfolder, SOCKET s1, sendFile** file);				//Ответ сервера на запрос

