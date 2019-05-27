#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack* createStack(){
    Stack* s = (Stack*) malloc(sizeof(Stack));

    if( s != NULL ){
        s->n = 0;
        s->head = NULL;
    }

    return s;
}

Node* createNode(double value){
    Node* n = (Node*) malloc(sizeof(Node));

    if( n != NULL ){
        n->value = value;
        n->next = NULL; 
    }

    return n;
}

Node* pop(Stack *s){
    if( s == NULL ) return NULL;
    if( s->head == NULL ) return NULL;

    Node *f = s->head;
    s->head = s->head->next;
    s->n--;

    return f;
}

void push(Stack *s, Node *n){
    if( s == NULL ) return;

    n->next = s->head;
    s->head = n;
    s->n++;

}

int freeStack(Stack* s){
    if( s != NULL ){
        Node* n;
        
        while( (n = pop(s)) != NULL ) free(n);
       
        free(s);

        return 1;
    }

    return 0;
}

int freeNode(Node* n){
    if( n != NULL ){
        free(n);
        return 1;
    }

    return 0;
}
