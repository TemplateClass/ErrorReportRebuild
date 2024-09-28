#pragma once
#include <stdio.h>
#include <string.h>
#include <Windows.h>

void DllMissingErrorMain(int ErrorType, FILE* ConfigFileReader, FILE* LogWriter) {
	SYSTEMTIME StartTime, EndTime;
	GetLocalTime(&StartTime);

	char Text[SIZE] = {}, Title[SIZE] = {};

	char MissingDll[SIZE] = "coredpus.dll";
	char ErrorProgram[SIZE] = "svchost.exe";

	fscanf(ConfigFileReader, "%s%s", MissingDll, ErrorProgram);
	sprintf(Text, TextList[ErrorType], MissingDll);
	sprintf(Title, TitleList[ErrorType], ErrorProgram);

	int UserChoose = MessageBoxA(NULL, Text, Title, MB_OK + MB_ICONERROR);

	GetLocalTime(&EndTime);

	WriteLog(LogWriter, StartTime, EndTime, "DLL_MISSING_ERROR", Text, Title, UserChoose);
}