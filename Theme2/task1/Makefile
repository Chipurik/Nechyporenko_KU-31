all: compile run

compile: main.c my-math.c
	gcc main.c my-math.c -o main.out -lm

run: main.out
	./main.out