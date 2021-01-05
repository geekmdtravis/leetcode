#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "reverseIntegerPop.h"

int main() {
    printf("Reversed: %d", reverse(-2143648));
    return 0;
}

int reverse(int x) {
    if (x <= INT_MIN || x >= INT_MAX) return 0;

    Stack *s = newStack();

    for (unsigned int i = abs(x); i != 0; i /= 10) push(s, i % 10);

    long retVal = 0;
    for (int curr = 0, end = s->top; curr <= end; curr++) 
        retVal += pop(s) * pow(10, (double)curr);
    retVal *= x < 0 ? -1 : 1;
    
    free(s);

    return retVal >= INT_MIN && retVal <= INT_MAX ? (int)retVal : 0;
}

Stack *newStack() {
    Stack *new = malloc(sizeof(Stack));
    new->top = -1;
    return new;
}

void push(Stack *s, unsigned short num) {
    s->data[++s->top] = num;
}

unsigned short pop(Stack *s) {
    return s->data[s->top--];
}

unsigned short peek(Stack *s) {
    return s->data[s->top];
}