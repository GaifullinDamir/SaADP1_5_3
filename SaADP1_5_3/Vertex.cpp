#include <iostream>
#include "Vertex.h"
#include "Interface.h"
using namespace std;

void treeInit(Vertex*& pRoot) { pRoot = nullptr; }

bool treeIsEmpty(Vertex* pRoot) { return pRoot == nullptr; }

void addVertex(Vertex*& pRoot, Vertex*& pCurrent, int data)
{
	if (treeIsEmpty(pRoot))
	{
		pRoot = new Vertex;
		pRoot->data = data;
		pRoot->left = pRoot->right = nullptr;
	}
	else
	{
		Vertex* vertex = new Vertex;
		vertex->data = data;
		vertex->left = vertex->right = nullptr;
		if(pCurrent->right ){ pCurrent->left = vertex; } //Если права вершина заполнена, то вернет true. А это значит, что левая пустая.
		else if (pCurrent->left){ pCurrent->right = vertex; }//Если левая вершина заполне, то вернет true. А это значит, что правая пустая.
		else
		{
			cout << "   Both branches are free. Add Left (1)/Right (2): ";
			switch (input())
			{
			case Left:{ pCurrent->left = vertex; break; }
			case Right:{ pCurrent->right = vertex; break;}
			default: cout << "   There is no such menu item." << endl; break;
			}
		}
	}
}

void searchVertex(Vertex*& pCurrent, Vertex*& pSearched, int searchedData, bool& check)
{
	bool stop = false;
	if (!stop)
	{
		if (pCurrent != nullptr)
		{
			if (pCurrent->data == searchedData) { pSearched = pCurrent; check = stop = true; }
			else
			{
				searchVertex(pCurrent->left, pSearched, searchedData, check);
				searchVertex(pCurrent->right, pSearched, searchedData, check);
			}
		}
	}
}

void showForward(Vertex* pCurrent, int level)
{
	if (pCurrent != nullptr)
	{
		for (int i = 0; i < level; i++) { cout << "   "; }
		cout << pCurrent->data << endl; level++;
		showForward(pCurrent->left, level);
		showForward(pCurrent->right, level);
	}
}

void showSymmetric(Vertex* pCurrent, int level)
{
	if (pCurrent != nullptr)
	{
		level++;
		showSymmetric(pCurrent->left, level);
		for (int i = 0; i < level - 1; i++) { cout << "   "; }
		cout << pCurrent->data << endl;
		showSymmetric(pCurrent->right, level);
	}
}

void showBackSymmetric(Vertex* pCurrent, int level)
{
	if (pCurrent != nullptr)
	{
		level++;
		showBackSymmetric(pCurrent->right, level);
		for (int i = 0; i < level - 1; i++) { cout << "   "; }
		cout << pCurrent->data << endl;
		showBackSymmetric(pCurrent->left, level);
	}
}

void treeClearMemory(Vertex*& pCurrent)
{
	if (pCurrent != nullptr)
	{
		treeClearMemory(pCurrent->left);
		treeClearMemory(pCurrent->right);
		delete pCurrent;
		pCurrent = nullptr;
	}
}