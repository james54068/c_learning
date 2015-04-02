# include <stdio.h>
int small_letter2capital_letter(char ch);
char dec2hex(int dec);
int main(void){
	printf("%c,%c\r\n",small_letter2capital_letter('B'),small_letter2capital_letter('g'));
	printf("%c\r\n",dec2hex(14));
} 

int small_letter2capital_letter(char ch){
	if(ch>='a'&&ch<='z') return 'A'+ch-'a'; 
	else if(ch>='A'&&ch<='Z') return 'a'+ch-'A';
	else return 0;
}
/*0~15*/
char dec2hex(int dec){
	return "0123456789ABCDEF"[dec];
}