#include "miniMax.h"


int** buf;



int heuritic(int** arr, int size){
	int user = 0, computer = 0;
	//Check Horizontal line
	for(int x=0;x<size;x++){
		int horizontalUser = 0;
		for(int y=0;y<size;y++) {
			int s = arr[x][y];
			if(s == -1) horizontalUser = -100;
			else if(s == 1) horizontalUser++; 
		}
		if(horizontalUser == 1) user += horizontalUser; 
		if(horizontalUser == 2) user += horizontalUser * 5; 
		if(horizontalUser == 3) user += horizontalUser * 6; 
		if(horizontalUser == 4) user += horizontalUser * 10; 
	}

	for(int x=0;x<size;x++){
		int horizontalComputer = 0;
		for(int y=0;y<size;y++) {
			int s = arr[x][y];
			if(s == 1) horizontalComputer = -100;
			else if(s == -1) horizontalComputer++; 
		}
		if(horizontalComputer == 1) user += horizontalComputer; 
		if(horizontalComputer == 2) user += horizontalComputer * 5; 
		if(horizontalComputer == 3) user += horizontalComputer * 6; 
		if(horizontalComputer == 4) user += horizontalComputer * 10; 
	}

	//Check vertical line
	for(int y=0;y<size;y++){
		int verticalUser = 0;
		for(int x=0;x<size;x++) {
			int s = arr[x][y];
			if(s == -1) verticalUser = -100;
			else if(s == 1) verticalUser++; 
		}
		if(verticalUser == 1) user += verticalUser; 
		if(verticalUser == 2) user += verticalUser * 5; 
		if(verticalUser == 3) user += verticalUser * 6; 
		if(verticalUser == 4) user += verticalUser * 10; 
	}

	for(int y=0;y<size;y++){
		int verticalComputer = 0;
		for(int x=0;x<size;x++) {
			int s = arr[x][y];
			if(s == 1) verticalComputer = -100;
			else if(s == -1) verticalComputer++; 
		}
		if(verticalComputer == 1) user += verticalComputer; 
		if(verticalComputer == 2) user += verticalComputer * 5; 
		if(verticalComputer == 3) user += verticalComputer * 6; 
		if(verticalComputer == 4) user += verticalComputer * 10; 
	}

	//Check diagonal link
	int leftUser = 0;
	for(int x=0;x<size;x++){
		int s = arr[x][x];
		if(s == -1) leftUser = -100;
		else if(s == 1) leftUser++;
	}
	if(leftUser == 1) user += leftUser;
	if(leftUser == 2) user += leftUser * 2;
	if(leftUser == 3) user += leftUser * 4;
	if(leftUser == 4) user += leftUser * 5;

	int rightUser = 0;
	for(int x=0;x<size;x++){
		int s = arr[size-1-x][x];
		if(s == -1) rightUser = -100;
		else if(s == 1) rightUser++;
	}
	if(rightUser == 1) user += rightUser;
	if(rightUser == 2) user += rightUser * 2;
	if(rightUser == 3) user += rightUser * 4;
	if(rightUser == 4) user += rightUser * 5;




	int leftComputer = 0;
	for(int x=0;x<size;x++){
		int s = arr[x][x];
		if(s == 1) leftComputer = -100;
		else if(s == -1) leftComputer++;
	}
	if(leftComputer == 1) user += leftComputer;
	if(leftComputer == 2) user += leftComputer * 2;
	if(leftComputer == 3) user += leftComputer * 4;
	if(leftComputer == 4) user += leftComputer * 5;


	int rightComputer = 0;
	for(int x=0;x<size;x++){
		int s = arr[size-1-x][x];
		if(s == 1) rightComputer = -100;
		else if(s == -1) rightComputer++;
	}
	if(rightComputer == 1) user += rightComputer;
	if(rightComputer == 2) user += rightComputer * 2;
	if(rightComputer == 3) user += rightComputer * 4;
	if(rightComputer == 4) user += rightComputer * 5;



	return user * 3 - computer * 4;
}




void linkedListToArray(board** gameBoard, int** buf, int size){
	for(int x=0;x<size;x++){
		board* head = gameBoard[x];
		for(int y=0;y<size;y++){
			buf[x][y] = head->data;
			head = head->link;
		}
	}
}
void arrayToLinkedList(int** buf, board** gameBoard, int size){
	for(int x=0;x<size;x++){
		board* head = gameBoard[x];
		for(int y=0;y<size;y++){
			head->data = buf[x][y];
			head = head->link;
		}
	}
}

void makeChild(int** arr, int size, int who){
	for(int x=0;x<size;x++)
		for(int y=0;y<size;y++)
			if(arr[x][y] == 0)
				arr[x][y] = who * 2;
}
void saveArray(int** buf, int** bbuf, int size){
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			buf[i][j] = bbuf[i][j];
}

int isArrTerminal(int** arr, int size, int who){
	for(int i=0;i<size;i++){
		int t = 1;
		for(int j=0;j<size;j++)
			if(arr[i][j] != who) t = 0;
		if(t) return 1;
	}
	for(int i=0;i<size;i++){
		int t = 1;
		for(int j=0;j<size;j++)
			if(arr[j][i] != who) t = 0;
		if(t) return 1;
	}
	
	int l = 1;
	for(int i=0;i<size;i++)
		if(arr[i][i] != who) l = 0;
	if(l)  return 1;

	int r = 1;
	for(int i=0;i<size;i++)
		if(arr[i][size-1-i] != who) r = 0;
	if(r)  return 1;

	return 0;
}
int isArrFull(int** arr, int size){
	int full = 1;
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			if(arr[i][j] == 0) full = 0;
	if(full) return 1;
	return 0;
}

int miniMax(board** gameBoard, int** arr, int size, int who, int depth){
	

	if(isArrTerminal(arr, size, who)) return INF;
	if(isArrFull(arr, size)) return DRAW * who;
	if(!depth) return heuritic(arr, size) * who;

	int bestValue = INF * 2;

	int** bbuf;
	bbuf = malloc(sizeof(int*)*10);
	for(int i=0;i<10;i++) bbuf[i] = calloc(sizeof(int),10);

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			bbuf[i][j] = arr[i][j];

	for(int i=0; i<size;i++) {
		for(int j=0;j<size;j++){
			if(bbuf[i][j] != 0) continue;
			bbuf[i][j] = -who;

			int v = -miniMax(gameBoard, bbuf, size, -who, depth-1);
			if(bestValue >= v){
				bestValue = v;
				if(buf == NULL) {
					buf = malloc(sizeof(int*)*10);
					for(int i=0;i<10;i++) buf[i] = calloc(sizeof(int),10);
				}
				if(Depth == depth) saveArray(buf, bbuf, size);
			}
			bbuf[i][j] = 0;
		}
	}

	if(Depth == depth) arrayToLinkedList(buf, gameBoard, size);

	return bestValue+100*who;
}

void setInit(int** arr, int size){
	if(arr[0][0] == 1) arr[size/2][size/2] = -1;
	else if(arr[size/2][size/2] == 1) arr[0][0] = -1;
	else if(arr[size-1][0] == 1) arr[size/2][size/2] = -1;
	else if(arr[0][size-1] == 1) arr[size/2][size/2] = -1;
	else if(arr[size-1][size-1] == 1) arr[size/2][size/2] = -1;
	else arr[size/2][size/2] = -1;
}



