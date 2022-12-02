all: compile run

compile: main.c
	gcc main.c task.c threads.c buffer.c -lpthread -lrt -o main.out

run: main.out
	./main.out