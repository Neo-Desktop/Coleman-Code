#include "NodeManager.h"

void NodeManager::Init(int initialSize) {
	Nodes = (NodeP*)malloc(sizeof(NodeP) * initialSize);
}

int NodeManager::Add(NodeP nodeIn) {
	NodeP arrnode;

	if (nodeCount + 1 > allocatedCount) {
		Nodes = (NodeP*)realloc(Nodes, sizeof(Node) * nodeCount);
	}

	// inserts at end
	Nodes[nodeCount] = nodeIn;
	Nodes[nodeCount]->self = nodeIn;
	Nodes[nodeCount]->left = Nodes[nodeCount-1];

	Nodes[nodeCount-1]->right = nodeIn;

	nodeCount++;
	Sort();
}

void NodeManager::Sort() {
	// A-Za-z0-9 sort
	int i = 0;

	if (nodeCount < 2) {
		return;
	}

	for (i = 0; i < nodeCount-1; i++) {
		if (strcmp(Nodes[i]->name, Nodes[i+1]->name) > 0) {
			Swap(i, i+1);
		}
	}
}

void NodeManager::Swap(int id1, int id2) {
	NodeP one, two;

	//left node
	one = Nodes[id1]->left;
	two = Nodes[id2]->left;
	Nodes[id1]->left = two;
	Nodes[id2]->left = one;

	//right node
	one = Nodes[id1]->right;
	two = Nodes[id2]->right;
	Nodes[id1]->right = two;
	Nodes[id2]->right = one;

	//node entry
	one = Nodes[id1];
	two = Nodes[id2];
	Nodes[id1] = two;
	Nodes[id2] = one;
}

NodeP NodeManager::GetAt(int index) {

}

boolean NodeManager::InsertAt(int index, NodeP nodeIn) {

}

boolean NodeManager::DeleteAt(int index) {

}

NodeManagerP NewNodeManager(int size) {
	NodeManagerP nodem;

	nodem = (NodeManagerP)malloc(sizeof(NodeManager));
	nodem->Init(5);

	return nodem;
}