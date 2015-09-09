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

	void Init(int initialSize);

	int Add(NodeP nodeIn);
	NodeP GetAt(int index);
	boolean InsertAt(int index, NodeP nodeIn);
	boolean DeleteAt(int index);

	void Sort();
	void Swap(int id1, int id2);

} NodeManager, *NodeManagerP;

NodeManagerP NewNodeManager(int size);

#endif