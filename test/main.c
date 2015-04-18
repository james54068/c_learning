# include <stdio.h>

void arrary(int c[]);

void main(void){
	int a=3,b=5;
	int c[10]={1,2,3,4,5};
	a=b=7;/*r->l b=7,a=b.*/
	printf("%d %d\r\n",a,b);
	a+=b+=2;/*r->l b=b+2,a=a+b*/
	printf("%d %d\r\n",a,b);
	printf("%d\r\n",sizeof(c));
	arrary(c);
}

void arrary(int *c){
	printf("%d\r\n",sizeof(c));
	printf("%d\r\n",c[2]);
}