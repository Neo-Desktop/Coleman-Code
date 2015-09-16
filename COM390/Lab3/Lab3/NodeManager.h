#include "Node.h"
#include "common.h"

#ifndef H_NODEMANAGER
#define H_NODEMANAGER

typedef struct {
private:
	int allocatedCount;
	int nodeCount;

public:
	NodeP *Nodes;
	NodeP startNode;

	void Init(int initialSize);
	int  Size();
	int  Length();

	void    Add(int aIn, float bIn, char *nameIn);
	NodeP   GetAt(int index);
	boolean InsertAt(int index, NodeP nodeIn);
	boolean DeleteAt(int index);

	void Sort();
	boolean Swap(int id1, int id2);

	void Destroy();
	void ReorderRefrence();

} NodeManager, *NodeManagerP;

#define N_INITIALSIZE 10
NodeManagerP NewNodeManager(int size = N_INITIALSIZE);

#endif