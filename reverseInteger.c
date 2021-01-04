#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int reverse(int x);

int main() {
    int result = reverse(-2147483412);
    printf("Result: %d", result);
    return 0;
}

int reverse(int x) {
    char *tmp = malloc(12 * sizeof(char));
    sprintf(tmp, "%d\n", x);

    int numChars = 0;
    for (numChars = 0; tmp[numChars] != '\n'; numChars++);

    short isNegative = x < 0 ? 1 : 0;
    int numDigits = isNegative ? numChars - 1 : numChars;

    char reversedString[numChars + 1];
    memset(reversedString, '\0', numChars);

    if (isNegative) 
        reversedString[0] = '-';

    int indexOffest = isNegative ? 1 : 0;
    for (int i = 0 ; i < numDigits ; i++) {
        reversedString[i + indexOffest] = tmp[numChars - 1 - i];
    }

    long reversed = atol(reversedString);
    return (reversed > INT_MAX || reversed < INT_MIN) ? 0 : (int)(reversed);
}
