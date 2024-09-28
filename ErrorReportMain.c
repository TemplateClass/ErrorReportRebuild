#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>

#include "BasicDefine.h"
#include "BasicFunction.h"
#include "MemoryError.h"
#include "DllMissingError.h"
#include "ExeError.h"

// We must change the way of getting string from config file.
// if we still use fscanf, it cannot read a space and doesnt fit for new error type.
// we have to change fgets, but i dont want to do it now. 

int ErrorType = DEFAULT_ERROR;

int main() {
	SetProcessDPIAware();
	initStrings();

	FILE* ConfigFileReader = fopen(CONFIG_FILENAME, "r");
	FILE* LogWriter = fopen(LOG_FILENAME, "at+");

	fscanf(ConfigFileReader, "%d", &ErrorType);

	switch (ErrorType) {
		case MEMORY_ERROR: {
			MemoryErrorMain(MEMORY_ERROR, ConfigFileReader, LogWriter);
			break;
		}

		case DLL_MISSING_ERROR: {
			DllMissingErrorMain(DLL_MISSING_ERROR, ConfigFileReader, LogWriter);
			break;
		}

		case EXE_ERROR: {
			ExeErrorMain(EXE_ERROR, ConfigFileReader, LogWriter);
			break;
		}
	}

	return 0;
}