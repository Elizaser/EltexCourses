all: link
link: main.o libaddition.so libdivision.so libmultiplication.so libsubtraction.so
	gcc main.c -o main -L.  -laddition -ldivision -lmultiplication -lsubtraction
libaddition.so: addition.o 
	gcc -shared addition.o -o libaddition.so
libdivision.so: division.o 
	gcc -shared division.o -o libdivision.so
libmultiplication.so: multiplication.o 
	gcc -shared multiplication.o -o libmultiplication.so
libsubtraction.so: subtraction.o
	gcc -shared subtraction.o -o libsubtraction.so
main.o:	main.c
	gcc -fpic main.c -c
addition.o: addition.c
	gcc -fpic addition.c -c
division.o: division.c
	gcc -fpic division.c -c
multiplication.o: multiplication.c
	gcc -fpic multiplication.c -c
subtraction.o: subtraction.c
	gcc -fpic subtraction.c -c
run:
	LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:$$PWD ./main
clean:
	rm *.o
	rm *.so
	rm main

