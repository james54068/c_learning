# include <stdio.h>
# include "sort.h"

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
/*left=0,right=9*/
int quick_sort(int *array,int left,int right){
	/*if left pivot is smallest && right pivot is largest*/
	if(left>=right)return 1; 
	int pivot=array[0],index=0;
	int i=0,number=right-left+1;
	swap(&array[0],&array[number-1]);
	for(i=0;i<number-1;i++){
		if(array[i]<pivot){
			swap(&array[i],&array[index++]);
		} 
	}
	swap(&array[index],&array[number-1]);
	/*recursive*/
	/*right*/
	quick_sort(&array[index+1],0,right-(index+1));
	/*left*/
	quick_sort(array,0,index-1);
	return 1;
}

void bubble_sort(int *array,int length){
	int i,j;
	for(i=0;i<length-1;i++){
		for(j=0;j<length-1-i;j++){
			if(array[j]>array[j+1]) swap(&array[j],&array[j+1]);
		}
	}
}

void insert_sort(int *array,int length){
	int i,j;
	for(i=1;i<length;i++){
		for(j=i;j>0;j--){
			if(array[j-1]>array[j]) swap(&array[j],&array[j-1]);
		}
	}
}

void selection_sort(int *array,int length){
	int i,j;
	for(i=0;i<length-1;i++){
		for(j=length-1;j>i;j--){
			if(array[j-1]>array[j]) swap(&array[j],&array[j-1]);
		}
	}
}

int merge_sort(int *array,int left,int right){
	int mid = (left+right)/2;
	if(right>left){
		/*left*/
		merge_sort(array,left,mid);
		/*right*/
		merge_sort(array,mid+1,right);
		merge(array,left,right);
	}	
	return 1;
}

static void merge(int *array,int left,int right){
	int i, j, k;
	int tmp[(right-left)+1];
    int mid = (left + right) / 2;

    for (k = 0, i = left, j = mid+1; i <= mid || j <= right; k++)
    {
        if (i > mid)
            tmp[k] = array[j++];
        else if (j > right)
            tmp[k] = array[i++];
        else if (array[i] < array[j])
            tmp[k] = array[i++];
        else
            tmp[k] = array[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++)
        array[i] = tmp[k];
}





