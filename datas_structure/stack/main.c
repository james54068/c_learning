#include <stdio.h>
#define size 10 

typedef struct{
	int contents[size];
	int top;
}stack;

void init_stack(stack *stack);
void push(stack *stack,int n);
int pop(stack *stack);

void main(void){
	stack stack1;
	init_stack(&stack1);
	push(&stack1,2);
	push(&stack1,5);
	push(&stack1,3);
	printf("%d %d %d \r\n",stack1.contents[0],stack1.contents[1],stack1.contents[2]);
	printf("%d \r\n",pop(&stack1));
	printf("%d %d %d \r\n",stack1.contents[0],stack1.contents[1],stack1.contents[2]);
}

void init_stack(stack *stack){
	int i=0;
	stack->top=0;
	for(;i<size;i++){
		stack->contents[i]=0;
	}
}

void push(stack *stack,int n){
	if(n<size){
		stack->contents[stack->top]=n;
		(stack->top)++;
	}else{
		printf("stack is full");
	}
}

int pop(stack *stack){
	int value;
	--(stack->top);
	value=stack->contents[stack->top];
	stack->contents[stack->top]=0;
	return value;
}