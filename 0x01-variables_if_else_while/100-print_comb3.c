#include<stdio.h>

/**
*main-Entrypoint
*
*Return:Always0(Success)
*/
intmain(void)
{
intnum1,num2;

for(num1=0;num1<10;num1++)
{
for(num2=num1+1;num2<10;num2++)
{
putchar(num1+'0');
putchar(num2+'0');

if(num1==8&&num2==9)
break;

putchar(',');
putchar('');
}
}

putchar('\n');

return(0);
}

