#include "Node.h"

void Node::Init(int aIn, float bIn, char *nameIn) {
	a = aIn;
	b = bIn;
	name = nameIn;
}

NodeP NewNode(int aIn, float bIn, char *nameIn) {
	NodeP out;

	out = (NodeP)malloc(sizeof(Node));
	out->Init(aIn, bIn, nameIn);

	return out;
}