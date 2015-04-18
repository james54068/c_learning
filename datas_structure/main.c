#include <stdio.h>
#include "stack.h"
#include "linked_list.h"

int main(void){
/*	array_stack stack1;
	stack1 = create_array_stack(5);
	init_array_stack(&stack1);
	push_array_stack(&stack1,2);
	push_array_stack(&stack1,3);
	pop_array_stack(&stack1);
	push_array_stack(&stack1,5);
	pop_array_stack(&stack1);
	printf("%d %d %d %d %d\r\n",stack1.contents[0],stack1.contents[1],stack1.contents[2],stack1.contents[3],stack1.contents[4]);
	destroy_array_stack(&stack1);
	printf("%d %d %d %d %d\r\n",stack1.contents[0],stack1.contents[1],stack1.contents[2],stack1.contents[3],stack1.contents[4]);
	*/

	/*
	int order=0,number=0;
	struct singly_node *singly_list = NULL;
	struct singly_node *search_list = NULL;
	singly_list = add_nodes_singly_linked_list(singly_list);
	// printf("///////enter search number////////\r\n");
	// scanf("%d",&number);
	// search_list = search_singly_linked_list_data(singly_list,number,&order);
	// printf("%d %d\r\n",order,search_list->data);
	// printf("///////enter search number////////\r\n");
	// scanf("%d",&number);
	// search_list = search_singly_linked_list_order(singly_list,3);
	// printf("%d\r\n",search_list->data);
	printf("///////enter del number////////\r\n");
	scanf("%d",&number);
	singly_list = del_node_singly_linked_list(singly_list,number);
	// printf("%d\r\n",search_list->data);
	search_list = search_singly_linked_list_data(singly_list,number,&order);
	order=0;
	// printf("%d %d\r\n",order,search_list->data);
	printf("///////enter search number////////\r\n");
	scanf("%d",&number);
	search_list = search_singly_linked_list_data(singly_list,number,&order);
	printf("%d %d\r\n",order,search_list->data);*/
	
	// printf("%d\r\n",x);
	// print();
	/*no point double_list to NULL->need create one to point as starter*/
	struct double_node list,*double_list,*search_list;
	/*init first one*/
	list.left=NULL;
	list.data=0;
	list.right=NULL;
	double_list=&list;
	int number;
	// double_list = add_double_linked_list(double_list,5);
	// double_list = add_double_linked_list(double_list,4);
	// printf("%d\r\n",double_list->right->data);
	double_list = add_nodes_double_linked_list(double_list);
	printf("///////enter search number////////\r\n");
	scanf("%d",&number);
	search_list = search_double_linked_list_data(double_list,number);
	printf("%d\r\n",search_list->data);
	printf("///////enter search number////////\r\n");
	scanf("%d",&number);
	search_list = search_double_linked_list_data(double_list,number);
	printf("%d\r\n",search_list->data);
	printf("///////enter del number////////\r\n");
	scanf("%d",&number);
	double_list=del_node_double_linked_list(double_list,number);
	printf("%d %d\r\n",double_list->data,double_list->right->data);
	
	
	
	return 0;
}

