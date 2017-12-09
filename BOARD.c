#include "BOARD.h"
#include <stdlib.h>
#include <stdio.h>


int getXY(board* b[], int x, int y){
	board* head = b[x];
	for(int i=0;i<y;i++) head = head->link;
	return head->data;
}
void putXY(board* b[], int x, int y, int who){
	board* head = b[x];
	for(int i=0;i<y;i++) head = head->link;
	head->data = who;
}

void makeBoard(board* b[], int size){
	for(int i=0;i<size;i++)
		makeNode(&b[i], size);
}

void makeNode(board** b, int size){
	board* head;
	for(int i=0;i<size;i++) {
		board* new = malloc(sizeof(board));
		new->data = 0;
		new->link = NULL;

		if(!i) head = new, *b= head;
		else head->link = new, head = new;
	}
}
void printBoard(board* b[], int size){
	for(int i=0;i<size;i++){
		board* head = b[i];
		while(head->link != NULL){
			printf("  %c  |", head->data == 0 ? ' ' : head->data == 1 ? 'O' : 'X');
			head = head->link;
		}
		printf("  %c\n", head->data == 0 ? ' ' : head->data == 1 ? 'O' : 'X');
		if(i != size - 1) for(int i=0;i<size*6-1;i++) printf("-"); puts("");
	}
}
