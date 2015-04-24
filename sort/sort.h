#ifndef __SORT_H_
#define __SORT_H_

void swap(int *a,int *b);
int quick_sort(int *array,int left,int right);
int bubble_sort(int *array,int left,int right);
int insert_sort(int *array,int left,int right);
int selection_sort(int *array,int left,int right);
int merge_sort(int *array,int left,int right);
static void merge(int *array,int left,int right);

#endif