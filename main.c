#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(void) {
    int n,i,verif,c;
    do{
    	verif = 0;
		printf("enter a command number:");
    	verif = scanf("%d", &n);
		if(verif != 1){
		printf("error!\n\n");
		c;
		while((c = getchar()) != '\n' && c != EOF ){
		}
		}	
	}while(verif != 1);
    
	Stack *s1 = create_stack(10);
    
    for(i = 0; i < n; i++) {
        printf("\nwrite a command %d\n1:push\n2:pop\n3:peek\n4:is_empty\n5:view_stack\n\n",i + 1);
        int command;
        do{
    	verif = 0;
    	verif = scanf("%d", &command);
		if(verif != 1){
		printf("error!\n\n");
		c;
		while((c = getchar()) != '\n' && c != EOF ){
		}
		}	
	}while(verif != 1);
        if(command == 1) {
            int value;
            printf("enter a num to adding:");
            if(scanf("%d", &value) == 1){
            	int* val = malloc(sizeof(int));
            	*val = value;
            	push(s1, (void*)val);
			}else{
				i--;
				c;
				while((c = getchar()) != '\n' && c != EOF ){
				}
				printf("error!\n\n");
				continue;
			}
           
        }
        else if(command == 2) {
            int* num = (int*)pop(s1);
            if(num == NULL){
                printf("empty\n");
            }else{
                printf("%d\n",*num);
            }
            
        }
        else if(command == 3) {
            int* num = (int*)peek(s1);
            if(num == NULL){
                printf("empty\n");
            }else{
                printf("%d\n",*num);
            }
        }
        else if(command == 4) {
            if(is_empty(s1)){
                printf("empty\n");
            }else{
                printf("not empty!\n");
            }
    	}
    	else if(command == 5) {
           view_stack(s1);
    	}
    	else{
    		i--;
    		printf("enter a valid command\n\n");
		}
    	
	}
    printf("\nfree_stack...");
    free_stack(s1);
    return 0;
}
