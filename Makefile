all: main.c stack.o
	gcc main.c -o main stack.o

stack.o: stack.c stack.h
	gcc -c stack.c stack.h
