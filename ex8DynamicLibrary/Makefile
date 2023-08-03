bin := calculator
obj := plus.o minus.o multiply.o divide.o
lib := libcalculate.so
CC := gcc
LD_FLAGS := -L. -lcalculate

$(bin): $(bin).o $(lib)
	$(CC) $^ -o $@ $(LD_FLAGS)
$(lib): $(obj)
	 $(CC) -shared $(obj) -o $(lib) 
%.o: %.c %.h
	$(CC) -fpic $< -c -o $@
run: 
	LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:$$PWD ./calculator
clean:
	rm *.o
	rm $(lib)
	rm $(bin)