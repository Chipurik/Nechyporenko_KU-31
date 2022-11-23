all: compile run-putenv-program-test run-setenv-program-test

compile: putenv-method.c setenv-method.c
	gcc putenv-method.c -o putenv-method.out
	gcc setenv-method.c -o setenv-method.out

run-putenv-program-test: putenv-method.out
	./putenv-method.out USERNAME someone

run-setenv-program-test: setenv-method.out
	./setenv-method.out NEW-ENVIRONMENT-VARIABLE somevalue


