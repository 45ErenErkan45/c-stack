#ifndef STACK_H
#define STACK_H

typedef struct {
    void** items;
    int top;
    int capacity;
} Stack;

 Stack* create_stack(int capacity);
 void push(Stack* stack, void* item);
 void* pop(Stack* stack);
 void* peek(Stack* stack);
 int is_empty(Stack* stack);
 void free_stack(Stack* stack);

#endif

