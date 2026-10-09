#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(void) {
    int n,i,verif;
    do{
    	verif = 0;
		printf("enter a command number:");
    	verif = scanf("%d", &n);
		if(verif != 1){
		printf("error!\n\n");
		getchar();
		}	
	}while(verif != 1);
    
	Stack *s1 = create_stack(10);
    
    for(i = 0; i < n; i++) {
        printf("\nwrite a command %d\n1:push\n2:pop\n3:peek\n4:is_empty\n\n",i + 1);
        char command[10];
        scanf("%s", command);
        
        if(strcmp(command, "push") == 0) {
            int value;
            printf("enter a num to adding:");
            if(scanf("%d", &value) == 1){
            	int* val = malloc(sizeof(int));
            	*val = value;
            	push(s1, (void*)val);
			}else{
				i--;
				getchar();
				printf("error!\n\n");
				continue;
			}
           
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
        else if(strcmp(command, "is_empty") == 0) {
            if(is_empty(s1)){
                printf("empty\n");
            }else{
                printf("not empty!\n");
            }
    	}
    	else{
    		i--;
    		printf("%s not a command\n\n", command);
		}
    	
	}
    printf("\nfree_stack...");
    free_stack(s1);
    return 0;
}
