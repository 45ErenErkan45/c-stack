#include <stdlib.h>
#include "stack.h"

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

void free_stack(Stack* stack) {
    int i;
	if(stack != NULL){
        for(i = 0; i < stack->capacity; ++i){
            free(stack->items[i]);
        }
        free(stack);
    }
}
