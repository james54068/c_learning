#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

array_stack create_array_stack(int size){
	array_stack s;
	s.contents = malloc(size*sizeof(int));
	if(s.contents==NULL) printf("Can not create stack");
	s.top = 0;
	s.size = size;
	return s;
}

void init_array_stack(array_stack *stack){
	int i=0;
	stack->top=0;
	for(;i<stack->size;i++){
		*((stack->contents)+i)=0;
	}
}

void push_array_stack(array_stack *stack,int n){
	if(stack->top<stack->size){
		*(stack->contents+stack->top++)=n;
	}else printf("stack is full\r\n");
}

int pop_array_stack(array_stack *stack){
	int value;
	if(stack->top>0){
		value=*(stack->contents+(--stack->top));
		*(stack->contents+stack->top)=0;
		return value;
	}else{
		printf("stack is empty\r\n");
		return 0;
	}
}

inline void destroy_array_stack(array_stack *stack){
	free(stack->contents);
}
