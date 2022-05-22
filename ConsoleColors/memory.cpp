#include "memory.h"


HANDLE memory::getProcess(const wchar_t* gameName)
{
	PROCESSENTRY32 entry;
	DWORD PID = NULL;
	entry.dwSize = sizeof(PROCESSENTRY32);
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (Process32First(snapshot, &entry) == TRUE)
	{
		while (Process32Next(snapshot, &entry) == TRUE)
		{
			std::wstring binPath = entry.szExeFile;
			if (binPath.find(gameName) != std::wstring::npos) {
				PID = entry.th32ProcessID;
				break;
			}
		}
	}


	if (PID != NULL)
	{
		HANDLE myHandle = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, PID);
		if (myHandle != NULL)
		{
			return myHandle;
		}
	}
	
}

template<typename T>
T memory::readMemory(HANDLE proc, LPVOID adr) {
	T val;
	ReadProcessMemory(proc, adr, &val, sizeof(T), NULL);
	return val;
}

template<typename T>
void memory::writeMemory(HANDLE proc, LPVOID adr, T val)
{
	WriteProcessMemory(proc, adr, &val, sizeof(T), NULL);
}