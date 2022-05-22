#pragma once
#include <iostream>
#include <Windows.h>



struct output
{
	enum Colors {
		nothing,
		blue,
		green,
		light_blue,
		red,
		purple,
		piss_yellow,
		white
	};


	void logError(const char* string);
	void logWarning(const char* string);
	void printC(const char* string, Colors color);



};

