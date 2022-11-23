all: compile run-with-help-option run-with-specific-mode run-with-file-option run-with-help-option-long run-with-specific-mode-long run-with-file-option-long

compile: main.c
	gcc main.c -o main.out

run-with-help-option: main.out
	./main.out -h

run-with-specific-mode: main.out
	./main.out -c

run-with-file-option: main.out
	./main.out -o main.out

run-with-help-option-long: main.out
	./main.out --help

run-with-specific-mode-long: main.out
	./main.out --compile

run-with-file-option-long: main.out
	./main.out --output main.out

