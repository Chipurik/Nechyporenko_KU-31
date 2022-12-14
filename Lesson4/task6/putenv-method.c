#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        char *string;
        value = argv[2];
        string = malloc(strlen(var)+strlen(value)+2);
        if (!string) {
            fprintf(stderr, "out of memory\n");
            return 1;
        }
        strcpy(string, var);
        strcat(string, "=");
        strcat(string, value);
        printf("Calling putenv with: %s\n", string);
        if (putenv(string) != 0) {
            fprintf(stderr, "putenv failed\n");
            free(string);
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
