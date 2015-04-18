# include <stdio.h>

void swap_without_temp(int *a,int *b);
int set_bit(int reg,int bit,int on_off);
inline int inverse_bit(int reg,int bit);
inline int switch_odd_even_bits(int reg);
inline int big2little(int reg);
int leading_set_bit(int reg);
inline int odd_even(int reg);
inline int test_set(int reg,int bit);
inline int toggle_bit(int reg,int bit);
inline int turn_off_right_most(int reg);
inline int Isolate_rightmost1(int reg);
inline int propagate_rightmost(int reg);
inline int Isolate_rightmost0(int reg);

int main(void){
	int a=3,b=5;
	swap_without_temp(&a,&b);
	printf("%d,%d\r\n",a,b);
	printf("%d\r\n",set_on_off_bit(5,1,1));
	printf("%d\r\n",inverse_bit(5,2));
	printf("%d\r\n",switch_odd_even_bits(55));
	printf("%x\r\n",big2little(0x12345678));
	printf("%d\r\n",leading_set_bit(0x02345678));
	printf("%d\r\n",odd_even(2));
	printf("%d\r\n",test_set(5,2));
	printf("%d\r\n",toggle_bit(5,1));
	printf("%d\r\n",turn_off_right_most(5));
	printf("%d\r\n",Isolate_rightmost1(12));
	printf("%d\r\n",propagate_rightmost(12));
	printf("%d\r\n",Isolate_rightmost0(5));
}
/*a,b must in same type*/
/*
*a^=*b;
*b^=*a;
*a^=*b;
*/
void swap_without_temp(int *a,int *b){
	// *a^=*b^=*a^=*b; undefined behavior
	*a^=*b;
	*b^=*a;
	*a^=*b;
}
/*turn on/off particular bit*/
int set_on_off_bit(int reg,int bit,int on_off){
	if(on_off){
		return reg|=(1<<bit);
	}else{
		return reg&=~(1<<bit);
	}
}
/*inverse bit*/
inline int inverse_bit(int reg,int bit){
	return reg^=(1<<bit);
}
/*exchange odd bits with even bits*/
inline int switch_odd_even_bits(int reg){
	return (reg&0xaaaaaaaa)>>1|(reg&0x55555555)<<1; 
}
/*endian conversion*/
inline int big2little(int reg){
	return ((reg&0x000000ff)<<24)|((reg&0x0000ff00)<<8)|((reg&0x00ff0000)>>8)|((reg&0xff000000)>>24);
}
/*
find leading set bit
Use counting leading zero trick
everytime divide into 2 part 
*/
int leading_set_bit(int reg){
	int x=0;
	if((reg&0xffff0000)==0){
		x+=16;
		reg=(reg<<16);
	} 
	if((reg&0xff000000)==0){
		x+=8;
		reg=(reg<<8);
	} 
	if((reg&0xf0000000)==0){
		x+=4;
		reg=(reg<<4);
	}
	if((reg&0xc0000000)==0){
		x+=2;
		reg=(reg<<2);
	}
	if((reg&0x80000000)==0){
		x+=1;
		reg=(reg<<1);
	}    
	return 32-x;
}
/*check integer is odd or even*/
inline int odd_even(int reg){
	return (reg&1);
}
/*test n bit is set*/
inline int test_set(int reg,int bit){
	if(reg&(1<<bit)) return 1;
	else return 0;	
}
/*toggle n bit*/
inline int toggle_bit(int reg,int bit){
	return reg^(1<<bit);
}
/*rightmost1  -> reg-1,-reg*/
/*Turn off the rightmost 1-bit 00101010->00101000 */
inline int turn_off_right_most(int reg){
	return reg&(reg-1);/*-reg=~reg+1*/
}
/*Isolate the rightmost 1-bit 01010100->00000100*/
inline int Isolate_rightmost1(int reg){
	return reg&(-reg);/*-reg=~reg+1*/
}
/*Right propagate the rightmostu 1-bit 01010000->01011111*/
inline int propagate_rightmost(int reg){
	return reg|(reg-1);
}
/*rightmost0 -> reg+1*/
/*Isolate the rightmost 0-bit 10101011->00000100*/
inline int Isolate_rightmost0(int reg){
	return (~reg)&(reg+1);
}
/*Turn on the rightmost 0-bit 10100011->10100111*/
inline int turn_on(int reg){
	return reg|(reg+1);
}