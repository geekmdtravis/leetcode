#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **fizzBuzz(int n, int *returnSize);

int main() {
    int returnSize;
    char **fizzBuzzed = fizzBuzz(3369, &returnSize);

    for (int i = 0; i < returnSize; i++) 
        printf("%s\n", fizzBuzzed[i]);

    return 0;
}

char **fizzBuzz(int n, int *returnSize){
    *returnSize = n;
    char **ret = malloc(n * sizeof(char*));
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i %5 == 0) 
            *ret = "FizzBuzz";
        else if (i % 3 == 0) 
            *ret = "Fizz";
        else if (i % 5 == 0) 
            *ret = "Buzz";
        else { 
            *ret = malloc(12 * sizeof(char));
            sprintf(*ret, "%d", i);
        }
        ret++;
    }
    return ret - n;
}