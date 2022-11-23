#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char *var, *value;

    if (argc == 1 || argc > 3) {
        fprintf(stderr, "usage: envir1 var [value]\n");
        return 1;
    }

    var = argv[1];
    value = getenv(var);
    if (value) {
        printf("Variable %s has value %s\n", var, value);
    } else {
        printf("Variable %s doesn't have value\n", var);
    }

    if (argc == 3) {
        printf("Calling setenv with: variable %s, value %s\n", var, argv[2]);

        if (setenv(var, argv[2], 1) != 0) {
            fprintf(stderr, "setenv failed\n");
            return 1;
        }

        value = getenv(var);
        if (value) {
            printf("New value %s equals %s\n", var, value);
        } else {
            printf("New value %s equals null", var);
        }
    }

    printf("\n");

    return 0;
}
