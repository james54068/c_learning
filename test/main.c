# include <stdio.h>

void main(void){
	int a=3,b=5;
	a=b=7;
	printf("%d %d\r\n",a,b);
	a+=b+=2;
	printf("%d %d\r\n",a,b);
}