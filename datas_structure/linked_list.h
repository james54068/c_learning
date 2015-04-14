#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

struct singly_node{
	int data;
	struct singly_node *next;
};

struct double_node{
	int data;
	struct double_node *right;
	struct double_node *left;
};

static struct singly_node *add_singly_linked_list(struct singly_node *first,int value);
struct singly_node *add_nodes_singly_linked_list(struct singly_node *list);
struct singly_node *search_singly_linked_list_data(struct singly_node *list,int value,int *order);
struct singly_node *search_singly_linked_list_order(struct singly_node *list,int order);
struct singly_node *del_node_singly_linked_list(struct singly_node *list,int value);

static struct double_node *add_double_linked_list(struct double_node *list,int value);
struct double_node *add_nodes_double_linked_list(struct double_node *list);
struct double_node *search_double_linked_list_data(struct double_node *list,int value);
#endif
