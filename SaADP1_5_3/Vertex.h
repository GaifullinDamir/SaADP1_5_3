#pragma once
struct Vertex
{
	int data;
	Vertex* left, * right;
};

void treeInit(Vertex*& pRoot);

bool treeIsEmpty(Vertex* pRoot);

void searchVertex(Vertex*& pCurrent, int searchedData);

void addVertex(Vertex*& pCurrent);

void showBackSymmetric(Vertex* pCurrent, int level);

void treeClearMemory(Vertex*& pCurrent);