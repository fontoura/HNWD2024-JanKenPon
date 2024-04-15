jankenpon: main.o
	gcc main.o -o jankenpon

main.o: main.c
	gcc -c main.c -o main.o
