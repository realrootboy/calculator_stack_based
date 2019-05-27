#ifndef STACK_H
#define STACK_H

typedef struct node{
    double value;
    struct node *next;
} Node;

typedef struct stack{
    int n;
    Node *head;
} Stack;

Stack* createStack();

Node* createNode(double value);

Node* pop(Stack *s);

void push(Stack *s, Node *n);

int freeStack(Stack* s);

int freeNode(Node* n);

#endif
