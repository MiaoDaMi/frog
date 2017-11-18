main: main.o move.o
	gcc -o main main.o move.o
main.o: main.c
	gcc -c -I. main.c
move.o: move.c
	gcc -c -I. move.c
clean:
	rm *.o main
