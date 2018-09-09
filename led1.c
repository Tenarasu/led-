/*  LED BLINKING USING SHIFT OPERATOR  */
#include<htc.h>
void delay();
void main()
{
	int i;
	TRISB=0;
	while(1)
	{
		unsigned char a=0x01;
		for(i=0;i<8;i++)
		{
			PORTB=a;
			delay(); //delay 1 for second 
			a=a<<1; //LED SHIFT STEP BY STEP THAT VALUES
		}
	}
}
/* Using delay for Timer1 */
void delay()
{
	int i;
	T1CKPS0=1;
	T1CKPS1=1;
	TMR1CS=0;
	for(i=0;i<10;i++)
	{
	TMR1H=0X3C;
	TMR1L=0XB0;
	TMR1ON=1;
	while(!TMR1IF);
	TMR1IF=0;
	}
	TMR1ON=0;
}
