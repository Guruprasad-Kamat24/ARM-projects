#include<lpc21xx.h>
#define IR (IO1PIN & (1<<24))
void delay(void);
void delay11(unsigned int );
void data1(unsigned int);
void command1(unsigned int);
void lcd1(void);
//void InitTimer0(void);
void step(void)
{
  int x=50;
	PINSEL1=0x0000000;
	IO0DIR=0xf0000000;
	while(1){
	//if(IR==0)
	//{
 	while(x!=0)
	{		
			IO0SET=0x10000000;
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
			delay();
		  delay();
			delay();
		  delay();
			delay();
		  delay();
			IO0CLR=0x10000000;
			delay();
			delay();
			delay();
		 
		  delay();
			delay();
		  delay();
			delay();
		  delay();
			IO0SET=0x20000000;
			delay();
			delay();
			delay();
		  delay();
			delay();
		  delay();
			delay();
		  delay();
			
			IO0CLR=0x20000000;
			delay();
			delay();
			delay();
		  delay();
			delay();
		  delay();
			delay();
		  delay();
			
			IO0SET=0x40000000;
			delay();
			delay();
			delay();
		  delay();
			delay();
		  
			IO0CLR=0x40000000;
			delay();
			delay();
			delay();
		  delay();
			delay();
		  delay();
			
			IO0SET=0x80000000;
			delay();
			delay();
			delay();
		  delay();
			delay();
		  delay();
			delay();
		 
			IO0CLR=0x80000000;
			delay();
			delay();
			delay();
		  delay();
			delay();
		  delay();
			delay();
		x=x-1;
	}
	lcd1();
	
//}
	}
}

void lcd1(void){
	unsigned char message[]= {"Access Granted"};
	unsigned int c[]={0x30,0x30,0x01,0x06,0x0e,0x80};
	unsigned int i,j;
	PINSEL0=0X00000000;
	IO0DIR=0x00000ffc;
	for(i=0;i<6;i++)
	{
		command1(c[i]);
		delay11(65000);
	}
	while(1)
	{
		command1(0x80);
		delay11(65000);
		for(j=0;j<14;j++)
		{
			data1(message[j]);
			delay11(65000);
		}
		delay11(10000);
		command1(0x01);
		delay11(10000);
	}
}


void command1(unsigned int x)
{
	unsigned int y;
	y=x;
	y=y & 0x0f;
	IO0CLR=0x000000fc;
	IO0CLR=0x00000004;
	IO0SET=y;
	IO0SET=0x00000008;
	delay11(2000);
	IO0CLR=0x00000008;
	y=x;
	y=y & 0x0f;
	y=y<<4;
	IO0CLR=0x00000004;
	IO0SET=y;
	IO0SET=0x00000008;
	delay11(2000);
	IO0CLR=0x00000008;
}
void data1(unsigned int a)
{
	unsigned int b;
	b=a;
	b=b & 0x0f;
	IO0CLR=0x000000fc;
	IO0SET=0x00000004;
	IO0SET=b;
	IO0SET=0x00000008;
	delay11(100);
	b=a;
	b=b& 0xf0;
	b=b<<4;
	IO0CLR=0x000000fc;
	IO0SET=0x00000004;
	IO0SET=b;
	IO0SET=0x00000008;
	delay11(100);
	IO0CLR=0x00000008;
}

void delay11(unsigned int x)
{
	unsigned int i;
	for(i=0;i<x;i++);
}
