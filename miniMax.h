#ifndef miniMax_h
#define miniMax_h

#include "BOARD.h"
#include "checkBoard.h"
#include <stdlib.h>
#define INF 999999999
#define DRAW 50
#define Depth 3

void setInit(int**, int);
int miniMax(board**, int**, int, int, int);
int isArrFull(int**, int);
int isArrTerminal(int**, int, int);
void saveArray(int**, int**, int);
void makeChild(int**, int, int);
void arrayToLinkedList(int**, board**, int);
void linkedListToArray(board**, int**, int);
int heuritic(int**, int);





#endif
