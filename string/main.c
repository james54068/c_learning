# include <stdio.h>
# include <string.h>
# include <stdlib.h>
int small_letter2capital_letter(char ch);
char dec2hex(int dec);
void inverse_arry_string(char *str);
char *inverse_string_literal(char *str);
/*
s is a pointer point to array (can not change pointer to other address,but can change array content)
"Hello World" is initializer
*/
char s[] = "Hello World";
/*
s1 is a pointer point to char (can change pointer to other address,but can not change array content(string literal store in read only aera))
point to read only aera where store "Hello World"
*/  
char *s1  = "Hello World"; 

int main(int argc, char *argv[]){
	char **p = &argv[1];
	printf("%s\r\n",*p);
	printf("%p\r\n",p);
	/***************/
	printf("%c,%c\r\n",small_letter2capital_letter('B'),small_letter2capital_letter('g'));
	printf("%c\r\n",dec2hex(14));
	/***************/
	printf("%s\r\n",s);
	printf("%p\r\n",s);
	/***************/
	printf("%s\r\n",s1);
	printf("%p\r\n",s1);
	s1++; 
	printf("%s\r\n",s1);
	printf("%p\r\n",s1);
	printf("%p\r\n",&s1[3]);
	/***************/
	char *s2 = "Hello World";

	// char *po= malloc(0);
	// printf("%p\r\n",po);
	printf("%d %d\r\n",sizeof(s),sizeof("Hello World"));
	inverse_arry_string(s);
	printf("%s\r\n",s);
	char *entry;
	entry=inverse_string_literal("abcdefg");
	printf("%s\r\n",entry);
	
	// printf("%p\r\n",s2);
	// *(s2+1)='k';
	// printf("%p\r\n",s2);
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

void inverse_arry_string(char *str){
	int length = strlen(str);
	int i=0,t=0;
	for(i=0;(str+length-1-i)-(str+i)>=1;i++){
		t = *(str+i);
		*(str+i)=*(str+length-1-i);
		*(str+length-1-i)=t;
	}
}

char *inverse_string_literal(char *str){
	char *entry;
	int length = strlen(str);
	/* length+1 => string + '/0' */
	entry = malloc(length+1);
	if(entry==NULL){
		printf("can not allocate memory");
		exit(EXIT_FAILURE);
	} 
	strncpy(entry,str,length+1);
	int i=0,t=0;
	/* length-1 => don't need to move '/0' */
	for(i=0;(entry+length-1-i)-(entry+i)>=1;i++){
		t = *(entry+i);
		*(entry+i)=*(entry+length-1-i);
		*(entry+length-1-i)=t;
	}
	return entry;
}

