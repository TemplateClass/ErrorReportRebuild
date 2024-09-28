#pragma once
#include <stdio.h>
#include <string.h>
#include <Windows.h>

void MemoryErrorMain(int ErrorType, FILE* ConfigFileReader, FILE* LogWriter) {
	SYSTEMTIME StartTime, EndTime;
	GetLocalTime(&StartTime);

	char Text[SIZE] = {}, Title[SIZE] = {};

	char Operate[SIZE] = "0x00000000";
	char Address[SIZE] = "0x00000000";
	char CannotBe[SIZE] = "read";
	char ErrorProgram[SIZE] = "svchost.exe";

	fscanf(ConfigFileReader, "%s%s%s%s", Operate, Address, CannotBe, ErrorProgram);
	sprintf(Text, TextList[ErrorType], Operate, Address, CannotBe);
	sprintf(Title, TitleList[ErrorType], ErrorProgram);

	int UserChoose = MessageBoxA(NULL, Text, Title, MB_OKCANCEL + MB_ICONERROR);

	GetLocalTime(&EndTime);

	WriteLog(LogWriter, StartTime, EndTime, "MEMORY_ERROR", Text, Title, UserChoose);
}