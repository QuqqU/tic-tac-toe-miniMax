#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BOARD.h"
#include "checkBoard.h"
#include "miniMax.h"

int who = 1;
int buf[10][10];

int main(){
	printf("What size? "); int size; scanf("%d", &size);	
	board** gameBoard = (board**)calloc(sizeof(board*), size); 
	makeBoard(gameBoard, size);
	printBoard(gameBoard, size);
	int firstTurn = 1;

	while(!isTerminal(gameBoard, size) && !isFull(gameBoard, size)){
		if(who == 1) {
			puts("-----User turn-----");
			int x, y;
			while(1){
				printf("Where (x, y) ? "); scanf("%d, %d", &x, &y);
				if(x>=size || y>=size || x<0 || y<0) continue;
				if(getXY(gameBoard, x, y) == 0) break;
			}
			putXY(gameBoard, x, y, who);
			printBoard(gameBoard, size);
		}
		else {
			puts("-----Computer turn-----");
			linkedListToArray(gameBoard, buf, size);
			if(firstTurn) {
				setInit(buf, size);
				arrayToLinkedList(buf, gameBoard, size);
				firstTurn = 0;
			}
			else miniMax(gameBoard, buf, size, 1, Depth);
			printBoard(gameBoard, size);
		}
		who *= -1;
	}
	for(int i=0;i<size*6-1;i++) printf("="); puts("");
	if(isTerminal(gameBoard, size)) printf("%s Wins!\n", who != 1 ? "User" : "Computer");
	else puts("There is no more space!\nREMATCH!!!");
	return 0;
}
