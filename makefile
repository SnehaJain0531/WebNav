all: main.o driver.o 
	gcc -o myapp main.o driver.o
main.o: main.c main.h
	gcc -c main.c
driver.o: driver.c driver.h 
	gcc -c driver.c
