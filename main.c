#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main() {
    int n,i;
    printf("enter a command num:");
	scanf("%d", &n);
    
    Stack *s1 = create_stack(10);
    
    for(i = 0; i < n; i++) {
        char command[10];
        printf("write a command\n1:push\n2:pop\n3:peek\n");
        scanf("%s", command);
        
        if(strcmp(command, "push") == 0) {
            int value;
            printf("enter a num to adding:");
            scanf("%d", &value);
            int* val = malloc(sizeof(int));
            *val = value;
            push(s1, (void*)val);
        }
        else if(strcmp(command, "pop") == 0) {
            int* num = (int*)pop(s1);
            if(num == NULL){
                printf("empty\n");
            }else{
                printf("%d\n",*num);
            }
            
        }
        else if(strcmp(command, "peek") == 0) {
            int* num = (int*)peek(s1);
            if(num == NULL){
                printf("empty\n");
            }else{
                printf("%d\n",*num);
            }
        }
    }
    
    free_stack(s1);
    return 0;
}

