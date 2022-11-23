#include <stdio.h>

int main() {

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

    return 0;
}
