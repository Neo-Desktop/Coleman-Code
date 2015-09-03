// Header file

#define LGBUFSIZE 1024
#define REGBUFSIZE 256
#define SMBUFSIZE 64

typedef struct {
	
	int a;
	int b;
	char buff[SMBUFSIZE];

}my_basic_structure_1;


void init();
void cleanup();
void pause();
