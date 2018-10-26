#include <stdio.h>

void print_bitwise_signed(signed char);
void print_bitwise_unsigned(unsigned char);


int main(){

unsigned char u_num=('7'-'0'); /*possible to just write 7*/
signed char num=-('7'-'0');
unsigned char u_num2=-('7'-'0'); /*giving unsigned char a negative value ,will return the numeric value
of all bits --> -7 unsigned is 249 */


print_bitwise_signed(num);
print_bitwise_unsigned(u_num);
print_bitwise_unsigned(u_num2);

return 0;
}

void print_bitwise_signed(signed char num)/*no good,prints reversed*/
	{
	printf("signed num before:%d\nbitwise:",num);
	int bit,i;	
	char mask='1'-'0';
	for(i=0;i<8;i++)
		{
		bit=num & mask;
		printf("%d",bit);
		bit >>=1;
		num >>=1;	
		}	
	printf("\nsigned num after:%d\n\n",num);
	}

/*void print_bitwise_unsigned(unsigned char num)
	{
	printf("unsigned num before:%d\nbitwise:",num);
	int bit,i;	
	char mask='1'-'0';
	for(i=0;i<8;i++)
		{
		bit=num & mask;
		printf("%d",bit);
		bit >>=1;
		num >>=1;	
		}	
	printf("\nunsigned num after:%d\n\n",num);
	}*/

void print_bitwise_unsigned(unsigned char num)
	{
	printf("unsigned num before:%d\nbitwise:",num);
	int bit,i;	
	unsigned char mask=0x80; /*without the 'unsigned' this value will return overflow error*/
	
	for(i=7;i>=0;i--)
		{
		bit=(num & mask) >> i;/*getting the i bit, from left to right*/	
		mask>>=1;	
		printf("%d",bit);			
		}	
	printf("\nunsigned num after:%d\n\n",num);
	}





