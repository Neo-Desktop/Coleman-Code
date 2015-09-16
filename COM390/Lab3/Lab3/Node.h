#include "common.h"

#ifndef H_NODE
#define H_NODE

typedef struct {
	int a;
	float b;
	char *name;

	NodeP left;
	NodeP right;
	NodeP self;

	void New(int aIn, float bIn, char *nameIn);

}Node, *NodeP;

#endif