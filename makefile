all: semaphores.c
	gcc -o semaphores semaphores.c

run: all
	./semaphores

clean:
	rm semaphores
	rm *.o
	rm *~
