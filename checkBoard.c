#include "checkBoard.h"

int isFull(board** gameBoard, int size){
	int isFull = 1;
	for(int x=0;x<size;x++)
		for(int y=0;y<size;y++)
			if(getXY(gameBoard, x,y) == 0) isFull = 0;
	if(isFull) return 1;
	return 0;
}


int isTerminal(board** gameBoard, int size){
	//Check the horizontal line
	for(int x=0;x<size;x++){
		int isHorizontalUser = 1;
		for(int y=0;y<size;y++)
			if(getXY(gameBoard, x, y) != 1) isHorizontalUser = 0;
		if(isHorizontalUser == 1) return 1;
		
		int isHorizontalComputer = 1;
		for(int y=0;y<size;y++)
			if(getXY(gameBoard, x, y) != -1) isHorizontalComputer = 0;
		if(isHorizontalComputer == 1) return 1;
	}

	//Check the vertical line
	for(int y=0;y<size;y++){
		int isVerticalUser = 1;
		for(int x=0;x<size;x++)
			if(getXY(gameBoard, x, y) != 1) isVerticalUser = 0;
		if(isVerticalUser == 1) return 1;
		
		int isVerticalComputer = 1;
		for(int x=0;x<size;x++)
			if(getXY(gameBoard, x, y) != -1) isVerticalComputer = 0;
		if(isVerticalComputer == 1) return 1;
	}
	
	//Check the diagonal line
	int isLeftUser = 1;
	for(int x=0;x<size;x++)
		if(getXY(gameBoard, x, x) != 1) isLeftUser = 0;
	if(isLeftUser == 1) return 1;

	int isRightUser = 1;
	for(int x=0;x<size;x++)
		if(getXY(gameBoard, x, size-1-x) != 1) isRightUser = 0;
	if(isRightUser == 1) return 1;

	int isLeftComputer = 1;
	for(int x=0;x<size;x++)
		if(getXY(gameBoard, x, x) != -1) isLeftComputer = 0;
	if(isLeftComputer == 1) return 1;

	int isRightComputer = 1;
	for(int x=0;x<size;x++)
		if(getXY(gameBoard, x, size-1-x) != -1) isRightComputer = 0;
	if(isRightComputer == 1) return 1;

	//Else, it is not terminal state
	return 0;
}


