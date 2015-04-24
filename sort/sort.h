#ifndef __SORT_H_
#define __SORT_H_

void swap(int *a,int *b);
int quick_sort(int *array,int left,int right);
void bubble_sort(int *array,int length);
void insert_sort(int *array,int length);
void selection_sort(int *array,int length);
int merge_sort(int *array,int left,int right);
static void merge(int *array,int left,int right);

#endif