/******************************************************************************
 *  Author: Amrit Panesar
 * Project: 3 - Special Characters
 *    Date: 09/25/2015
 * Purpose: Sanitize a random string to only allow a-zA-Z0-9 without regex
 *****************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <string.h>

#define FILTERPAIRS 5
#define PAIR 2

char filter[FILTERPAIRS][PAIR];
char *Buffer;

const char * RandomStr = "sdjsn9i3ms;sa;'smsn92;w;''[w0p4;dsmsdf";

int i, j, k = 0;

void init() {
	filter[0][0] = 0; // control characters
	filter[0][1] = 31;

	filter[1][0] = 32; // puncutation
	filter[1][1] = 47;

	filter[2][0] = 58; // puncutation
	filter[2][1] = 64;

	filter[3][0] = 91; //
	filter[3][1] = 96;

	filter[4][0] = 123;
	filter[4][1] = 255;
}

void shutdown() {
	printf("\n%s\n", "Press any key to continue. . . ");
	getch();
}

int main (int argc, char** argv) {
	init();

	Buffer = strdup(RandomStr);

	printf("%s:\n\n\t%s\n", "Start", Buffer);

	for (i = 0; i < FILTERPAIRS; i++) {
		for (j = 0; j < strlen(Buffer); j++) {
			if (Buffer[j] >= filter[i][0] && Buffer[j] <= filter[i][1]) {
				Buffer[j] = ' ';
			}
		}
	}

	printf("%s:\n\n\t%s\n", "Result", Buffer);

	shutdown();
}