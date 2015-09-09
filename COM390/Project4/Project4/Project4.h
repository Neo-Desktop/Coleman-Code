/******************************************************************************
 *  Author: Amrit Panesar
 * Project: 4 - Structs/Malloc
 *    Date: 09/08/2015
 * Purpose: Create a multidimensional array on the fly and populate its children
 *          Display the results.
 *****************************************************************************/

#include <conio.h>
#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

#define true 1;
#define false 0;

typedef struct
{
  int speed;
  int distance;
  time_t currentTimestamp;
} TravTimeStruct, *TtimeStruct;

#include "Helper.h"
