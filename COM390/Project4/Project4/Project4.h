
#include <conio.h>
#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include <time.h>

#define true 1;
#define false 0;

typedef struct 
{
  float speed;
  float distance;
  float timetraveled;
} TravTimeStruct, *TtimeStruct;


void init();
void down();
void pause();
void clrscr();