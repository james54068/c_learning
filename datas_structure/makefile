main:main.o stack.o linked_list.o
	gcc -o main main.o stack.o linked_list.o
main.o:main.c stack.h linked_list.h
	gcc -c main.c
stack.o:stack.c stack.h
	gcc -c stack.c
linked_list.o:linked_list.c linked_list.h
	gcc -c linked_list.c
#clean
clean:
	rm *.o
	rm main
#excute main
execute:
	./main
gdb:
	gdb
