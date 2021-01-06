#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **fizzBuzz(int n, int *returnSize);

int main() {
    int returnSize;
    char **fizzBuzzed = fizzBuzz(15, &returnSize);

    return 0;
}

char **fizzBuzz(int n, int *returnSize) {
    *returnSize = n;
    char **retVal = malloc(sizeof(char*) * n);
    for (int i = 0; i <= n; i++) {
        retVal[++i] = malloc(sizeof(char) * 12);
        if (i % 3 == 0 && i % 5 == 0)
            sprintf(retVal[++i], "%s", "FizzBuzz");
        else if (i % 3 == 0)
            sprintf(retVal[++i], "%s", "Fizz");
        else if (i % 5 == 0)
            sprintf(retVal[++i], "%s", "Buzz");
        else {
            sprintf(retVal[++i], "%d", i);
        }
    }
    return retVal;
}