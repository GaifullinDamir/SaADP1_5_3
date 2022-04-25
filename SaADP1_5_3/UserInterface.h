#pragma once
#include "Vertex.h"
enum userInterface
{
	ShowMenu,
	Left = 1,
	Right = 2,
	Exit,
	Continue = 1,
};

void printMainMenu();
int userInput();
void workWithUser(Vertex*& pRoot);
