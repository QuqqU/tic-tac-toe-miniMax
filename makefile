CC = gcc



20171689.out : BOARD.o 20171689.o checkBoard.o miniMax.o
	$(CC) -g -fsanitize=address -o $@ BOARD.o 20171689.o checkBoard.o miniMax.o

clean :
	rm -rf *.o *.out

miniMax.o : miniMax.c
	gcc -g -fsanitize=address -c -o $@ $<

checkBoard.o : checkBoard.c
	gcc -g -fsanitize=address -c -o $@ $<

BOARD.o : BOARD.c
	gcc -g -fsanitize=address -c -o $@ $<

20171689.o : 20171689.c
	gcc -g -fsanitize=address -c -o $@ $<


