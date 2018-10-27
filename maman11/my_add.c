/*
maman11
name: Shachar Elmaleh
id: 302871678
*/
#include <stdio.h>

/*
This program implements a bitwise ADD operator on 2 values in their binari representation.
input: 2 positive integers.
output: the 2 input numbers and the result of their addition in binari base as well as decimal.
*/
unsigned int my_add(unsigned int, unsigned int); 
void print_num_bitwise(unsigned int); /*auxiliary function that prints a number bit by bit*/

int main()
{
   unsigned int a=5,b=7,res;
   res=my_add(a,b);
   printf("result=%d -->",res);
   print_num_bitwise(res);

   return 0;

}


unsigned int my_add(unsigned int a, unsigned int b)
{
unsigned int res_mask=1,bit_mask=1,a_bit,b_bit,carry_bit=0,result=0;
int i,add_res=0;
/*
res_mask - mask that updates the results with new calculation
bit_mask - used to get the current bit from a and b
a_bit - current a bit
b_bit - current b bit
carry_bit - indicates when an arithmetic carry or borrow has been generated
add_res is a result of single addition.
*/
printf("a=%d --> ",a);
print_num_bitwise(a);
printf("b=%d --> ",b);
print_num_bitwise(b);
for(i=0; i<20; i++)
{
	a_bit=(bit_mask & a) >>i;
	b_bit=(bit_mask & b) >>i;
	add_res=a_bit+b_bit+carry_bit;

	if(add_res == 1)
	{
		result=result | res_mask;
		carry_bit=0;
	}

	if(add_res == 2)
	{
		carry_bit=1;
	}

	if(add_res == 3)
	{
		result=result | res_mask;
		carry_bit=1;
	}

	bit_mask<<=1;
	res_mask<<=1;
}
 return result;
}

void print_num_bitwise(unsigned int num)
{
	int bit,i;	
	unsigned int mask=0x80000; /*without the 'unsigned' this value will return overflow error*/
	
	for(i=19;i>=0;i--)
		{
		bit=(num & mask) >> i;/*getting the i bit, from left to right*/	
		mask>>=1;	
		printf("%d",bit);			
		}	
	printf("\n");
}