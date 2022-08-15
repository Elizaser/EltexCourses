all: run
run: main.o libcalculate.a
	gcc main.o -o main -L. -I. -lcalculate
libcalculate.a: addition.o division.o multiplication.o subtraction.o
	ar rc libcalculate.a addition.o division.o multiplication.o subtraction.o
main.o:	main.c
	gcc main.c -c
addition.o: addition.c
	gcc addition.c -c
division.o: division.c
	gcc division.c -c
multiplication.o: multiplication.c
	gcc multiplication.c -c
subtraction.o: subtraction.c
	gcc subtraction.c -c
clean:
	rm *.o
	rm *.a
