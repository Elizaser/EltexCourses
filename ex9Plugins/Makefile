bin := calculator
plugins := plus.so minus.so multiply.so divide.so 
CC := gcc

all: $(plugins) $(bin)
%.so: %.o
	gcc -shared $< -o lib$(<:.o=.so)	 
%.o: %.c %.h
	$(CC) $< -fpic -c -o $@
$(bin): calculator.h calculator.c main.c
	$(CC) calculator.c main.c -o $@ -ldl -g
run: 
	./calculator ./libplus.so  ./libminus.so ./libmultiply.so ./libdivide.so
clear:
	rm *.so
	rm calculator