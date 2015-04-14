#ifndef __STACK_H_
#define __STACK_H_
 
typedef struct{
	int *contents;
	int top;
	int size;
}array_stack;

array_stack create_array_stack(int size);
void init_array_stack(array_stack *stack);
void push_array_stack(array_stack *stack,int n);
int pop_array_stack(array_stack *stack);
inline void destroy_array_stack(array_stack *stack);

#endif