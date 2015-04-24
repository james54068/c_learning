# include <stdio.h>
# include "sort.h"
int (*sort[])(int *array,int left,int right) = {quick_sort,
												merge_sort,
												bubble_sort,
												insert_sort,
												selection_sort};
int main(){
	int i=0,array[10];
	printf("enter 10 numbers\r\n");
	for(i=0;i<10;i++){
		scanf("%d",&array[i]);
	}
	sort[0](array,0,9);
	printf("***************\r\n");
	printf("%d %d %d %d %d %d %d %d %d %d\r\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6],array[7],array[8],array[9]);
	sort[1](array,0,9);
	printf("***************\r\n");
	printf("%d %d %d %d %d %d %d %d %d %d\r\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6],array[7],array[8],array[9]);
	sort[2](array,0,9);
	printf("***************\r\n");
	printf("%d %d %d %d %d %d %d %d %d %d\r\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6],array[7],array[8],array[9]);
	sort[3](array,0,9);
	printf("***************\r\n");
	printf("%d %d %d %d %d %d %d %d %d %d\r\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6],array[7],array[8],array[9]);
	sort[4](array,0,9);
	printf("***************\r\n");
	printf("%d %d %d %d %d %d %d %d %d %d\r\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6],array[7],array[8],array[9]);
	return 0;
}
