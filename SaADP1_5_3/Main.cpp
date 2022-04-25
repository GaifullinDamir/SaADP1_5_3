#include <iostream>
#include "Vertex.h"
#include "Interface.h"

int main()
{
	Vertex* pRoot;
	treeInit(pRoot);
	interface(pRoot);
	treeClearMemory(pRoot);
}