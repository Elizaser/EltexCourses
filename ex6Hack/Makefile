all:
	echo 0 > sudo /proc/sys/kernel/randomize_va_space
	gcc login.c -fno-stack-protector -no-pie  -g -o hack
run:
	./hack < test
clear:
	rm hack
	rm sudo