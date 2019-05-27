#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(int argc, char *argv[]){
    
    int i = 0;
    double entry = 0;

    if( argc <= 1 ) return -1;
    
    Stack *s = createStack();
    Node *n = NULL;

    if( s == NULL ) goto freeA;

    for( i = 1 ; i < argc ; i++ ){
        if((entry = atof(argv[i])) || (strlen(argv[i]) == 1 && argv[i][0] ==
        '0')){
            n = createNode(entry);

            if( n == NULL ) goto freeA;

            push(s, n);
        } else {
            if( s->n < 2 ) goto syntaxError;
            
            n = pop(s);
            entry = n->value;
            freeNode(n);

            n = pop(s);
            
            if(strlen(argv[i]) > 1 ) goto syntaxError;
            switch(argv[i][0]){
                case '+':
                    entry = n->value + entry;         
                break;
                case '-':
                    entry = n->value - entry;;
                break;
                case '/':
                    entry = n->value / entry;
                break;
                case '*':
                    entry = n->value * entry;
                break;
                default:
                    freeNode(n);
                    goto syntaxError;
            }

            freeNode(n);

            n = createNode(entry);

            push(s, n);
        }
    }

    goto freeB; 

    syntaxError:
    
    printf("Error on syntax !\n");
    goto freeB;

    freeA:
    
    printf("Error on Alloc Memory !\n");

    freeB:
   
    if( s->head != NULL && i == argc ) 
        if( s->head->next == NULL ) printf("Results: %lf\n", s->head->value);
        else printf("Error on syntax !\n");

    freeStack(s);

    return 0;
}
