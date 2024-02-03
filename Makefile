output : main.o board.o tree.o
	gcc main.o board.o tree.o -o prog 

test : test.o board.o tree.o
	gcc test.o board.o tree.o -o test

main.o : main.c
	gcc -c main.c

board.o: board.c board.h
	gcc -c board.c 

tree.o: tree.c tree.h
	gcc -c tree.c

test.o : test.c
	gcc -c test.c

clean :
	rm *.o

debug : main.o board.o tree.o
	gcc main.o board.o tree.o -o prog_debug  -g
