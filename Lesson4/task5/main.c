#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    if (argc == 2) {
        char *environmentVariableValue = getenv(argv[1]);
        char *value = malloc(strlen(environmentVariableValue)+1);
        strcpy(value, environmentVariableValue);

        if (value) {
            printf("Variable %s possesses the value: %s\n", argv[1], value);
        } else {
            printf("Variable %s doesn't has the value\n", argv[1]);
        }
    } else {
        printf("Error!!! Wrong number of arguments (expected 1 after call program)\n");
    }

    return 0;
}
