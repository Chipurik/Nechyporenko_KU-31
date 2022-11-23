#include <stdio.h>
#include <stdlib.h>

void showEnvironment();

int main(int argc, char **argv) {

    if (argc > 2) {
        fprintf(stderr, "Too many arguments\n");
        return 1;
    }

    showEnvironment();

    if (argc == 2) {
        printf("Deleting variable %s from environment\n", argv[1]);
        if (unsetenv(argv[1]) != 0) {
            fprintf(stderr, "Cannot unset %s\n", argv[1]);
            return 1;
        }
    } else {
        printf("Deleting all environment\n");
        clearenv();
    }

    showEnvironment();

    printf("\n");

    return 0;
}

void showEnvironment() {
    extern char **environ;

    char **env = environ;
    if (env) {
        printf("Environment variable list start\n");
        while(*env) {
            printf("\t%s\n", *env);
            env++;
        }
        printf("Environment variable list end\n");
    } else {
        printf("Environment variable list is empty\n");
    }
}
