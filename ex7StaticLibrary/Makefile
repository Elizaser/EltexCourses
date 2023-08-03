bin := calculator
obj := plus.o minus.o multiply.o divide.o
lib := libcalculate.a
CC := gcc
LD_FLAGS := -L.  -lcalculate

$(bin): $(bin).o $(lib)
	$(CC) $^ -o $@ $(LD_FLAGS)
$(lib): $(obj)
	 ar rc $(lib) $(obj)
%.o: %.c %.h
	$(CC) $< -c -o $@
clean:
	rm *.o
	rm $(lib)
	rm $(bin)