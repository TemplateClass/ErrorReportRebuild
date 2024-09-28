#pragma once
#include <stdio.h>
#include <string.h>
#include <Windows.h>

void ExeErrorMain(int ErrorType, FILE* ConfigFileReader, FILE* LogWriter) {
	SYSTEMTIME StartTime, EndTime;
	GetLocalTime(&StartTime);

	char Text[SIZE] = {}, Title[SIZE] = {};

	char ErrorName[SIZE] = "unknown software exception";
	char ErrorCode[SIZE] = "0x00000000";
	char Address[SIZE] = "0x0000000000000000";
	char ErrorProgram[SIZE] = "svchost.exe";

	//	fscanf(ConfigFileReader, "%s%s%s%s", ErrorName, ErrorCode, Address, ErrorProgram);
	sprintf(Text, TextList[ErrorType], ErrorName, ErrorCode, Address);
	sprintf(Title, TitleList[ErrorType], ErrorProgram);

	int UserChoose = MessageBoxA(NULL, Text, Title, MB_OKCANCEL + MB_ICONERROR);

	GetLocalTime(&EndTime);

	WriteLog(LogWriter, StartTime, EndTime, "EXE_ERROR", Text, Title, UserChoose);
}