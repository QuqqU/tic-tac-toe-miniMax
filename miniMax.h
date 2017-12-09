#ifndef miniMax_h
#define miniMax_h

#include "BOARD.h"
#include "checkBoard.h"

#define INF 999999999
#define DRAW 50
#define Depth 3

void setInit(int[10][10], int);
int miniMax(board**, int[10][10], int, int, int);
int isArrFull(int[10][10], int);
int isArrTerminal(int[10][10], int, int);
void saveArray(int[10][10], int[10][10], int);
void makeChild(int[10][10], int, int);
void arrayToLinkedList(int[10][10], board**, int);
void linkedListToArray(board**, int[10][10], int);
int heuritic(int[10][10], int);





#endif
