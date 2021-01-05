#ifndef REVERSE_INTEGER_H_INCLUDED
#define REVERSE_INTEGER_H_INCLUDED

typedef struct stack {
    int top;
    unsigned short data[10];
} Stack;

int reverse(int x);
Stack *newStack();
void push(Stack *s, unsigned short num);
unsigned short pop(Stack *s);
unsigned short peek(Stack *s);

#endif