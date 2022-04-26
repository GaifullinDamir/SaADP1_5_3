#pragma once
struct Vertex
{
	int data;
	Vertex* left, * right;
};

void treeInit(Vertex*& pRoot);

bool treeIsEmpty(Vertex* pRoot);

void searchVertex(Vertex*& pCurrent, Vertex*& pSearched, int searchedData, bool& check);

void addVertex(Vertex*& pRoot, Vertex*& pCurrent, int data);

void showForward(Vertex* pCurrent, int level);

void showSymmetric(Vertex* pCurrent, int level);

void showBackSymmetric(Vertex* pCurrent, int level);

void treeClearMemory(Vertex*& pCurrent);