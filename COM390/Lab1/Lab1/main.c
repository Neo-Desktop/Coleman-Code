#include <stdio.h>
#include <string.h>


char* name1 = "Mickey Mouse";
char* name2 = "Minnie Mouse";

int retval;

void pause();

int main (int argc, char** argv) {

	retval = strcmp(name1, name2);

	switch (retval) {
	case -1: 
		printf("%d: %s %s %s", retval, name1, "is shorter than", name2);
		break;
	case 0:
		printf("%d: %s %s %s", retval, name1, "is equal to", name2);
		break;
	case 1:
		printf("%d: %s %s %s", retval, name1, "is greater than", name2);
		break;
	default:
		printf("%s: %d", "Undefined return value", retval);
	}

	pause();
}

void pause() {
	getch();
}