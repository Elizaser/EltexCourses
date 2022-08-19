PLUGINS=plugins/
all: plugins link 
link: main.o $(PLUGINS)libaddition.so $(PLUGINS)libdivision.so $(PLUGINS)libmultiplication.so $(PLUGINS)libsubtraction.so
	gcc main.c -o main -L $(PLUGINS) -laddition -ldivision -lmultiplication -lsubtraction -ldl -g
$(PLUGINS)libaddition.so: addition.o 
	gcc -shared addition.o -o $@
$(PLUGINS)libdivision.so: division.o 
	gcc -shared division.o -o $@
$(PLUGINS)libmultiplication.so: multiplication.o 
	gcc -shared multiplication.o -o $@
$(PLUGINS)libsubtraction.so: subtraction.o
	gcc -shared subtraction.o -o $@
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
plugins: 
	mkdir plagins

run:
	LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:$$PWD/$(PLUGINS) ./main
clean:
	rm *.o
	rm $(PLUGINS)*.so
	rm main
