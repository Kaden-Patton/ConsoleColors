#include "output.h"




void output::logError(const char* string)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Colors::white);
	std::cout << "\n[";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Colors::red);
	std::cout << "ERROR";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Colors::white);
	std::cout << "] ";

	std::cout << string;
}

void output::printC(const char* string, Colors color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << string;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Colors::white);

}
