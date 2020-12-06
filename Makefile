CC = gcc
FLAGS = -Wall -g
all : main libmyBank.a
main: main.o libmyBank.a
	$(CC) $(FLAGS)  -o main main.o libmyBank.a 

libmyBank.a : myBank.o
	ar -rcs libmyBank.a myBank.o
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

.PHONY: all clean

clean:
	rm myBank.o main.o libmyBank.a main
