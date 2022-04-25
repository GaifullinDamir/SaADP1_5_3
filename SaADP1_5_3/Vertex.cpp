#include <iostream>
#include "Vertex.h"
#include "UserInterface.h"
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
		if (pCurrent->left != nullptr && pCurrent->right != nullptr) { cout << "   The vertex is full." << endl; }
		else if(pCurrent->left == nullptr && pCurrent->right != nullptr)
		{
			Vertex* vertex = new Vertex;
			vertex->data = data;
			vertex->left = vertex->right = nullptr;
			pCurrent->left = vertex;
		}
		else if (pCurrent->left != nullptr && pCurrent->right == nullptr)
		{
			Vertex* vertex = new Vertex;
			vertex->data = data;
			vertex->left = vertex->right = nullptr;
			pCurrent->right = vertex;
		}
		else
		{
			cout << "   Both branches are free. Add Left (1)/Right (2)." << endl;
			switch (userInput())
			{
			case Left:
			{
				Vertex* vertex = new Vertex;
				vertex->data = data;
				vertex->left = vertex->right = nullptr;
				pCurrent->left = vertex;
				break;
			}
			case Right:
			{
				Vertex* vertex = new Vertex;
				vertex->data = data;
				vertex->left = vertex->right = nullptr;
				pCurrent->right = vertex;
				break;
			}
			default:
				cout << "   There is no such menu item." << endl;
				break;
			}
		}
	}
}

void searchVertex(Vertex*& pCurrent, int searchedData)
{
	bool stop = false;
	while (stop)
	{
		if (pCurrent != nullptr)
		{
			std::cout << pCurrent->data << std::endl;
			if (pCurrent->data == searchedData) { stop = true; }
			else
			{
				searchVertex(pCurrent->left, searchedData);
				searchVertex(pCurrent->right, searchedData);
			}
		}
	}
}

void showBackSymmetric(Vertex* pCurrent, int level)
{
	if (pCurrent != nullptr)
	{
		level++;
		showBackSymmetric(pCurrent->right, level);
		for (int i = 0; i < level - 1; i++) { cout << "\t"; }
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
	}
}