#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <string>

class memory
{
public:
	HANDLE getProcess(const wchar_t*);

	template<typename T>
	T readMemory(HANDLE proc, LPVOID adr);

	template<typename T>
	void writeMemory(HANDLE proc, LPVOID adr, T val);

};

