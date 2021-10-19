all: main.o linked.o
	gcc -o main main.o linked.o

main.o: main.c linked.h
	gcc -c main.c

linked.o: linked.c
	gcc -c linked.c

run:
	./main

clean:
	rm *.o
