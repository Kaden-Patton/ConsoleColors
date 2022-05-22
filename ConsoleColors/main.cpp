#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include "output.h"
#include "memory.h"
using std::cout;

int main()
{
	output out;
	memory mem;


	//mem.getProcess(L"csgo.exe");


	int v1 = rand() % 10000 + 1;
	int v2 = rand() % 10000 + 1;

	int result = v1 + v2;

	std::cout << v1 << "\n" << v2 << "\n" << result;

	out.printC("This is a test", out.blue);

	out.logError("damn you fucked up");

	return 0;
}