#include<lpc21xx.h>
#include "buz.h"
#include "stepp.h"
#include "checkk.h"
#include "ldc.h"
#include "seriall.h"
#include "extint.h"
#include "timer.h"
//#define IR (IO1PIN & (1<<24))
//void extint0_ISR(void)__irq;
unsigned char mg;

int main()
{
	int x=0,i,m=0,j; 
	serial();
	while(1)
	{
	//unsigned int f;
	//PINSEL2=0x00000000;
	//IO1DIR=0x00000000;
		//f=IOPIN1;
		//f = f & 0x00100000; 
for(j=0;j<3;j++)
	{
for(i=0;i<7;i++)
{ 
  while(!(U0LSR & 0x01));
   mg=U0RBR;
   U0THR=mg;
  delay();
	delay();
  delay();
	delay();
	delay();
	delay();
	delay();
	delay();
	delay();
  delay();
	
  if(U0THR==98)
  {
   x=U0THR;
		delay();
	delay();
  }
  else if(U0THR==118)
  {
   x=x+U0THR;
		delay();
	delay();
  
  }
  else if(U0THR==97)
  {
   x=x+U0THR;
		delay();
	delay();
  }
	else if(U0THR==64)
  {
   x=x+U0THR;
		delay();
	delay();
  }
	else if(U0THR==49)
  {
   x=x+U0THR;
		delay();
	delay();
  }
	else if(U0THR==50)
  {
   x=x+U0THR;
		delay();
	delay();
  }
	else if(U0THR==51)
  {
   x=x+U0THR;
   check(x);
		delay();
	delay();
  }
  else if(U0THR==99 || U0THR<=100 || U0THR>=101  || U0THR>=102  || U0THR>=103  || U0THR>=104  || U0THR>=105  || U0THR>=106  || U0THR>=107  || U0THR>=108  || U0THR>=109  || U0THR>=110  || U0THR>=111  || U0THR>=112  || U0THR>=113  || U0THR>=114  || U0THR>=115  || U0THR>=116  || U0THR>=117  || U0THR>=119  || U0THR>=120  || U0THR>=121  || U0THR>=122)
  {
		m++;
		if(m==3)
		{
			check1();
			delay();
			delay();
		}
		 else if(m==1||m==2||m==0)

     {

  unsigned char mesa1[]={" Wrong password "};

  unsigned int k;

   for(k=0;k<20;k++)

  {

     while(!(U0LSR & 0x20));

      U0THR=mesa1[k];

  }
		delay();
		delay();
  }
 }
}
}
	delay();
}
}




/*void delay()
{
unsigned int i;
for(i=0;i<10000;i++);
}

void serial()
{
  PINSEL0=0X00000005;
  U0LCR= 0X83;
  U0DLL=0X61;
  U0LCR=0X03;
}*/

/*void check(int x)
{
  unsigned char msg[]={" You Are Welcome!"};
  unsigned int i;
 if(x==313)
 {
    for(i=0;i<17;i++)
    {
      while(!(U0LSR & 0x20));
       U0THR=msg[i];
    }  
		step(); //calling stepper
    
    delay(); delay();// calling lcd		
		lcd();// calling lcd 
    
 }
}


void check1()
{
  unsigned char msg1[]={"Get Out!!"};
  unsigned int i;
   for(i=0;i<9;i++)
  {
     while(!(U0LSR & 0x20));
      U0THR=msg1[i];
  }
   buzzer();  //calling buzzer
}*/

/*void lcd(void)
{
	unsigned char message[]= {"hello"};
	unsigned int c[]={0x30,0x30,0x20,0x20,0x28,0x01,0x06,0x0e,0x89};
	unsigned int i,j;
	PINSEL0=0X00000005;
	IO0DIR=0x000000fc;
	for(i=0;i<9;i++)
	{
		command(c[i]);
		delay();
	}
	while(1)
	{
		command(0x89);
		delay();
		for(j=0;j<5;j++)
		{
			data(message[j]);
			delay();
		}
		delay();
		command(0x10);
		delay();
	}
}


void command(unsigned int x)
{
	unsigned int y;
	y=x;
	y=y & 0x0f;
	IO0CLR=0x000000fc;
	IO0CLR=0x00000004;
	IO0SET=y;
	IO0SET=0x00000008;
	delay();
	IO0CLR=0x00000008;
	y=x;
	y=y & 0x0f;
	y=y<<4;
	IO0CLR=0x00000004;
	IO0SET=y;
	IO0SET=0x00000008;
	delay();
	IO0CLR=0x00000008;
}


void data(unsigned int a)
{
	unsigned int b;
	b=a;
	b=b & 0x0f;
	IO0CLR=0x000000fc;
	IO0SET=0x00000004;
	IO0SET=b;
	IO0SET=0x00000008;
	delay();
	b=a;
	b=b& 0x0f;
	b=b<<4;
	IO0CLR=0x000000fc;
	IO0SET=0x00000004;
	IO0SET=b;
	IO0SET=0x00000008;
	delay();
	IO0CLR=0x00000008;
}
*/
/*void step(void)
{
  int x=100;
	PINSEL2=0x0010000;
	IO0DIR=0xf0000000;
	IO1DIR=0x00000000;
	//x=IOPIN1;
	//x=x & 0x00f00000;

 	while(x!=0)
	{	//if(x==0x00100000)
		//{
			IO0SET=0x10000000;
			delay();
			IO0CLR=0x10000000;
			delay();
			IO0SET=0x20000000;
			delay();
			IO0CLR=0x20000000;
			delay();
			IO0SET=0x40000000;
			delay();
			IO0CLR=0x40000000;
			delay();
			IO0SET=0x80000000;
			delay();
			IO0CLR=0x80000000;
			delay();
		//}
		//else
		//{
		delay(); delay(); delay(); delay(); delay();
			IO0SET=0x80000000;
			delay();
			IO0CLR=0x80000000;
			delay();
			IO0SET=0x40000000;
			delay();
			IO0CLR=0x40000000;
			delay();
			IO0SET=0x20000000;
			delay();
			IO0CLR=0x20000000;
			delay();
			IO0SET=0x10000000;
			delay();
			IO0CLR=0x10000000;
			delay();
		//}
   x=x-1;
	}

}

void buzzer(void)
{
	PINSEL0=0x00000000;
	IODIR0=0x00000200;    ///po.9 made output
	IOCLR0=0x00000200;
	while(1)
	{
		IOSET0=0x00000200;
		delay();
		IOCLR0=0x00000200;
		delay();
	}
} */
