#include <stdio.h>
#include <conio.h>
#include <string.h>

const char* HELLO ="I love Porgramming in C\n";
const char* TOKENS = " ";
const int TOKENINDEX = 1; // insert name after token 0

char name[256], out[256];
char* token, nextToken = NULL;

int main(int argc, char** argv) {

	printf("%s\n:", "Please enter your name");
	gets_s(name, sizeof(name));

	strcpy(out, HELLO);

	token = strtok_s(out, TOKENS, &nextToken);

	for (int i = 0; token != NULL; i++) {
		if (i == TOKENINDEX) {
			printf(", %s,", name);
		}

		if (i == 0) {
			printf("%s", token);
		} else {
			printf(" %s", token);
		}
		
		token = strtok_s(NULL, TOKENS, &nextToken);
	}

	printf("\n%s\n", "Press any key to continue. . .");
	_getch();

	return 0;
}