all: semaphores.c
	gcc -o semaphores semaphores.c

run: all
	./semaphores -c 4
	./semaphores -v
	./semaphores -c 3
	./semaphores -v
	./semaphores -r

clean:
	rm semaphores
	rm *.o
	rm *~
