#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int reverse(int x);

int main() {
    int result = reverse(2147483647);
    printf("Result: %d", result);
    return 0;
}

int reverse(int x) {
    bool isNegative = x < 0;
    // 12 accounts for 32 bit int, sign, and terminating newline.
    const int MAX_SIZE = 12;
    char tmp[MAX_SIZE];
    sprintf(tmp, "%d\n", x);

    int numChars = 0;
    while(tmp[numChars] != '\n') {
        numChars++;
    }
    // excludes the negative sign.
    int numDigits = isNegative ? numChars - 1 : numChars;

    char reversedString[numChars];
    if (isNegative) 
        reversedString[0] = '-';

    int indexOffest = isNegative ? 1 : 0;
    for (int i = 0 ; i < numDigits ; i++) {
        reversedString[i + indexOffest] = tmp[numChars - 1 - i];
    }

    return atoi(reversedString);
}
