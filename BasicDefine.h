#pragma once
#include <Windows.h>
#include <string.h>

#define SIZE 255

#define CONFIG_FILENAME "Config.ini"
#define LOG_FILENAME "ErrorReportLog.log"

#define MEMORY_ERROR 1
#define DLL_MISSING_ERROR 2
#define EXE_ERROR 3 

#define DEFAULT_ERROR MEMORY_ERROR

char ButtonPressType[SIZE][SIZE];
char IconType[SIZE][SIZE];
char ButtonType[SIZE][SIZE];
char TextList[SIZE][SIZE];
char TitleList[SIZE][SIZE];

void initButtonPressTypeString() {
	strcpy(ButtonPressType[IDOK], "确定");
	strcpy(ButtonPressType[IDCANCEL], "取消");
	strcpy(ButtonPressType[IDABORT], "终止");
	strcpy(ButtonPressType[IDRETRY], "重试");
	strcpy(ButtonPressType[IDIGNORE], "忽略");
	strcpy(ButtonPressType[IDYES], "是");
	strcpy(ButtonPressType[IDNO], "否");
	strcpy(ButtonPressType[IDTRYAGAIN], "重试");
	strcpy(ButtonPressType[IDCONTINUE], "继续");
}

void initTextString() {
	strcpy(TextList[MEMORY_ERROR], "\"%s\" 指令引用的 \"%s\" 内存。该内存不能为 \"%s\"。\n\n要终止程序，请单击“确定”。\n要调试程序，请单击“取消”。");
	strcpy(TextList[DLL_MISSING_ERROR], "无法启动此程序，因为计算机中丢失 %s。尝试重新安装该程序以解决此问题。");
	strcpy(TextList[EXE_ERROR], "应用程序发生异常 %s (%s)，位置为 %s。\n\n要终止程序，请单击“确定”。\n要调试程序，请单击“取消”。");
}

void initTitleString() {
	strcpy(TitleList[MEMORY_ERROR], "%s - 应用程序错误");
	strcpy(TitleList[DLL_MISSING_ERROR], "%s - 系统错误");
	strcpy(TitleList[EXE_ERROR], "%s - 应用程序错误");
}

void initStrings() {
	initButtonPressTypeString();
	initTextString();
	initTitleString();
}