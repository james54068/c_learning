#include <stdio.h>
#include <stdlib.h>
struct node{
	int number;
	struct node *next; 
};
struct node *add_linked_list(struct node *list,int n);
struct node *add_series_to_linked_list(void);
struct node *search_list(struct node *first,int n,int *order);
struct node *del_node(struct node *first,int n);

int main(void)
{
	struct node *first = NULL;
	int order = 0, number = 0;
	// first = add_linked_list(first,10);
	// first = add_linked_list(first,20);
	first = add_series_to_linked_list();
	printf("///////enter search number////////\r\n");
	scanf("%d",&number);
	search_list(first,number,&order);
	printf("%d\r\n",order);
	printf("///////enter number to delete////////\r\n");
	scanf("%d",&number);
	del_node(first,number);
	printf("%d %d %d\r\n",first->number,first->next->number,first->next->next->number);
	return 0;
}

struct node *add_linked_list(struct node *list,int n){
	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	new_node->number = n;
	new_node->next = list;
	return new_node;
}

struct node *add_series_to_linked_list(void){
	struct node *first;
	int i;
	printf("enter numbers!(enter 0 to leave loop)\r\n");
	for(;;){
		scanf("%d",&i);
		if(i==0) return first;
		first = add_linked_list(first,i);
	}
}

struct node *search_list(struct node *first,int n,int *order){
	struct node *p;
	for(p = first;p != NULL;p = p->next){
		(*order)++;
		// printf("%d\r\n",*order);
		if(p->number == n) return p;
	}
	return NULL;
}

struct node *del_node(struct node *first,int n){
	struct node *p,*last;
	for(p = first,last = NULL;p != NULL&& p->number!=n;last = p , p = p->next)
		;
	if(p==NULL) return first;
	if(last==NULL) first = first->next;
	else last->next = p->next ;
	free(p);
	return first;
}



