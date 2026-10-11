#include <stdlib.h>
#include "stack.h"
#include <stdio.h>
Stack* create_stack(int capacity) {
    Stack *st = malloc(sizeof(Stack));
    st->items = malloc(sizeof(void*) * capacity);
    st->top = 0;
    st->capacity = capacity;
    return st;
}

void push(Stack* stack, void* item) {
    if(stack->top < stack->capacity){
        stack->items[stack->top++] = item;
    }else{
    	printf("stack is full!!!\n\n");
	}
}

void* pop(Stack* stack) {
    if(stack->top == 0){
    return NULL;
    }
    stack->top -= 1;
    return stack->items[stack->top];
}

void* peek(Stack* stack) {
    if(stack->top == 0){
    return NULL;
    }
    stack->top -= 1;
    void* it = stack->items[stack->top];
    stack->top += 1;
    return it;
}


int is_empty(Stack* stack) {
    if(stack->top == 0){
    return 1;
    }
    return 0;
}

void view_stack(Stack* stack){
	int i;
	for(i = stack->top - 1; i >= 0; --i){
		printf(" %d :| %3d |\n",i,*((int*)stack->items[i]));
	}	
		
}


void free_stack(Stack* stack) {
    int i;
	if(stack != NULL){
        for(i = 0; i < stack->capacity; ++i){
            free(stack->items[i]);
        }
        free(stack);
    }
}
