main:main.o sort.o 
	gcc -o main main.o sort.o 
main.o:main.c sort.h 
	gcc -c main.c
stack.o:sort.c sort.h
	gcc -c sort.c
#clean
clean:
	rm -f *.o
	rm main
#excute main
execute:
	./main
gdb:
	gdb