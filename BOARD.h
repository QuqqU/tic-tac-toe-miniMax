#ifndef BOARD_H
#define BOARD_H


typedef struct _node {
	int data;
	struct _node *link;
} board;

int getXY(board**, int, int);
void putXY(board**, int, int, int);
void makeBoard(board**, int);
void makeNode(board**, int);
void printBoard(board**, int);


#endif
