#include "NodeManager.h"

void NodeManager::Init(int initialSize) {
	Nodes = (NodeP*)malloc(sizeof(NodeP) * initialSize);
}

int NodeManager::Length() {
	return nodeCount;
}

int NodeManager::Size() {
	return allocatedCount;
}

void NodeManager::Sort() {
	// A-Za-z0-9 sort
	int i = 0;

	if (Size() < 2) {
		return;
	}

	for (i = 0; i < Size()-1; i++) {
		if (strcmp(Nodes[i]->name, Nodes[i+1]->name) > 0) {
			Swap(i, i+1);
		}
	}
}

void NodeManager::ReorderRefrence() {
	int i;
	NodeP curNode = startNode;
	for (i = 0; i < nodeCount; i++) {
		Nodes[i] = curNode;
		curNode = curNode->right;
	}
}

boolean NodeManager::Swap(int id1, int id2) {
	NodeP one, oneL, oneR;
	NodeP two, twoL, twoR;

	one = GetAt(id1);
	two = GetAt(id2);
	if (one == NULL || two == NULL) {
		return false;
	}

	//left node
	oneL = one->left;
	oneR = one->right;

	//right node
	twoL = two->left;
	twoR = two->right;

	//swap
	one->left = twoL;
	one->right = twoR;
	two->left = oneL;
	two->right = twoR;

	return true;
}

NodeP NodeManager::GetAt(int index) {
	int i;
	NodeP curNode;
	if (index > nodeCount) {
		return NULL;
	}
	for (i = 0; i < nodeCount; i++) {
		curNode = Nodes[0];
	}
	return curNode;
}

boolean NodeManager::InsertAt(int index, NodeP nodeIn) {
	int i;
	NodeP leftNode;
	NodeP curNode;
	NodeP rightNode;

	// make more room if we don't have any more
	if (nodeCount + 1 > allocatedCount) {
		Nodes = (NodeP*)realloc(Nodes, sizeof(Node) * (nodeCount + (nodeCount /2)));
	}

	curNode = GetAt(index);
	leftNode = curNode->left;
	rightNode = curNode->right;

	nodeCount++;
}

boolean NodeManager::DeleteAt(int index) {
	NodeP node = GetAt(index);
	if (node == NULL) {
		return false;
	}
	
	NodeP left = node->left;
	NodeP right = node->right;

	left->right = right;
	right->left = left;

	free(node);
	return true;
}

void NodeManager::Destroy() {
	int i;
	for (i = 0; i < Length() - 1; i++) {
		free(Nodes[i]);
	}
}

void NodeManager::Add(int aIn, float bIn, char *nameIn) {
	NodeP out;

	out = (NodeP)malloc(sizeof(Node));
	out->New(aIn, bIn, nameIn);
	InsertAt(nodeCount - 1, out);
}

NodeManagerP NewNodeManager(int size) {
	NodeManagerP nodem;

	nodem = (NodeManagerP)malloc(sizeof(NodeManager));
	nodem->Init(size);

	return nodem;
}