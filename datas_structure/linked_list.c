#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

/*single linked list*/
static struct singly_node *add_singly_linked_list(struct singly_node *list,int value){
	struct singly_node *new_node;
	new_node = malloc(sizeof(struct singly_node));
	if(new_node == NULL){
		printf("Can not create node");
		exit(EXIT_FAILURE);
	} 
	new_node->data = value;
	new_node->next = list;
	return new_node;
}

struct singly_node *add_nodes_singly_linked_list(struct singly_node *list){
	// struct singly_node *first;
	int data;
	printf("enter numbers!(enter 0 to leave loop)\r\n");
	for(;;){
		scanf("%d",&data);
		if(data==0) return list;
		list = add_singly_linked_list(list,data);
	}
}
/*list can not to be NULL*/
struct singly_node *search_singly_linked_list_data(struct singly_node *list,int value,int *order){
	struct singly_node *current;
	for(current=list;current!=NULL;current=current->next,(*order)++){		
			if(current->data==value) return current;
	}
	printf("Can not find\r\n");
	return NULL;
}

struct singly_node *search_singly_linked_list_order(struct singly_node *list,int order){
	int i=0;
	struct singly_node *current;
	for(current=list;i<order,current!=NULL;i++,current=current->next){
		if(i==order) return current;
	}
	printf("Can not find\r\n");
	return NULL;
}

struct singly_node *del_node_singly_linked_list(struct singly_node *list,int value){
	struct singly_node *current,*last;
	for(current=list,last=NULL;(current!=NULL)&&(current->data!=value);last=current,current=current->next);		
	if(current==NULL) return list;
	else if(last==NULL) list=list->next;
	else last->next=current->next;
	free(current);
	return list;
}

/*double linked list*/
static struct double_node *add_double_linked_list(struct double_node *list,int value){
	struct double_node *new_node;
	new_node = malloc(sizeof(struct double_node));
	if(new_node == NULL){
		printf("Can not create node");
		exit(EXIT_FAILURE);
	} 
	new_node->right=list;
	list->left=new_node;
	new_node->data=value;
	new_node->left=NULL;
	return new_node;
}

struct double_node *add_nodes_double_linked_list(struct double_node *list){
	int data;
	printf("enter numbers!(enter 0 to leave loop)\r\n");
	for(;;){
		scanf("%d",&data);
		if(data==0) return list;
		list = add_double_linked_list(list,data);
	}
}

struct double_node *search_double_linked_list_data(struct double_node *list,int value){
	struct double_node *right,*left;
	int lflag=1,rflag=1;
	printf("search %d\r\n",list->data);
	if(list->data==value) return list;

	if(list->right!=NULL){
		right = list->right;
		if(right->data==value) return right;
	}else rflag=0;
	

	if(list->left!=NULL) {
		left  = list->left;
		if(left->data==value) return left;
	}else lflag=0;
	

	while(rflag!=0||lflag!=0){
		if(rflag){
			if(right->data==value) return right;
			if(right->right!=NULL){
				right = right->right;		
			}else rflag=0;	
		}
		if(lflag){
			if(left->data==value) return left;
			if(left->left!=NULL){
				left = left->left;			
			}else lflag=0;
		}	
	}
	printf("Can not find node\r\n");
	return NULL;		
}

struct double_node *del_node_double_linked_list(struct double_node *list,int value){
	struct double_node *search_node;
	search_node = search_double_linked_list_data(list,value);
	if(search_node!=NULL){
		/*left end*/
		if(search_node->left==NULL&&search_node->right!=NULL){
			list=search_node->right;
			list->left=NULL;
			free(search_node);
			return list;
		}
		/*right end*/
		//else if(search_node->left!=NULL&&search_node->right==NULL){
	
		// 	// list=search_node->left->left;
		// 	// list->right=NULL;
		// 	// free(search_node);
		// 	// return list;
		// /*only one*/	
		// }
		else if(search_node->left==NULL&&search_node->right==NULL){
			list->data=0;
			return list;
		/*normal one*/
		}else{
			search_node->left->right=search_node->right;
			search_node->right->left=search_node->left;
			free(search_node);
			return list;
		}
	}
	return NULL;		 
}