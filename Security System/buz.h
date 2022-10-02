#include<lpc21xx.h>
void delay(void);
void buzzer()
{  
	int x=1000;
	PINSEL0=0x00000000;
	IODIR0=0x00008000;    ///po.14 made output
	IOCLR0=0x00008000;
	while(x!=0)
	{
		IOSET0=0x00008000;
    delay();
	  delay();
		delay();
		IOCLR0=0x00008000;
		x--;
	}
} 
