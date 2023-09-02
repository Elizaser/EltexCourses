CC := gcc
bin := fileInOut
obj := main.o fInOut.o

$(bin): $(obj)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $< -c -o $@ 

$(obj): fInOut.h	

clean:
	rm *.o
	rm $(bin) 