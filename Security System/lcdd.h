#include<lpc21xx.h>
void delay(void);
void data(unsigned int);
void command(unsigned int);
void lcd(int x)
{
	unsigned char message[]= {"Access Granted"};
	unsigned char message1[]= {"Access Denied!"};
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
			if(x==1)
			{
			data(message[j]);
				delay();
			}
			else if(x==2)
			{
				data(message1[j]);
				delay();
			}
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
		delay();
		delay();
		delay();
	IO0CLR=0x00000008;
	y=x;
	y=y & 0x0f;
	y=y<<4;
	IO0CLR=0x00000004;
	IO0SET=y;
	IO0SET=0x00000008;
	delay();
		delay();
		delay();
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
		delay();
		delay();	delay();	delay();	delay();
	b=a;
	b=b& 0x0f;
	b=b<<4;
	IO0CLR=0x000000fc;
	IO0SET=0x00000004;
	IO0SET=b;
	IO0SET=0x00000008;
	delay();	delay();	delay();	delay();	delay();	delay();	delay();
	IO0CLR=0x00000008;
}
