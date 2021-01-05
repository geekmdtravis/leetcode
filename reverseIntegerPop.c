#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "reverseIntegerPop.h"

int main() {
    printf("Reversed: %d", reverse(-3431));
    return 0;
}

// TODO: implement using a queue, not a stack. Need FIFO structure for this to work.
// Or, just read directly from the data in the stack in reverse order (hacky/ugly).
int reverse(int x) {
    Stack *s = newStack();
    unsigned short isNegative = x < 0 ? 1 : 0;

    for (int tmp = isNegative ? -x : x; tmp != 0; tmp /= 10) push(s, tmp % 10);

    long retVal = 0;
    while(s->top >= 0) retVal += pop(s) * (int)(pow(10, (double)s->top));

    retVal *= isNegative ? -1 : 1;

    return retVal >= INT_MIN && retVal <= INT_MAX ? (int)retVal : 0;
}

Stack *newStack() {
    Stack *new = malloc(sizeof(Stack));
    new->top = -1;
}

void push(Stack *s, unsigned short num) {
    s->data[++s->top] = num;
}

unsigned short pop(Stack *s) {
    unsigned short popped = s->data[s->top--];

    return popped;
}

unsigned short peek(Stack *s) {
    return s->data[s->top];
}