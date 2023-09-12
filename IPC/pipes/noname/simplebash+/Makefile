CC := gcc
bin := simpleBash
obj := main.o simpleBash.o parsString.o
incl := simpleBash.h parsString.h

$(bin): $(obj)
	$(CC) $^ -o $@
%.o: %.c
	$(CC) $< -c -o $@

$(obj): $(incl)

clean:
	rm *.o
	rm $(bin)