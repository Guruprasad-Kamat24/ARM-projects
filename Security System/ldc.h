#include<lpc21xx.h>
void delay1(unsigned int );
void data(unsigned int);
void command(unsigned int);
void lcd(int x)
{
	unsigned char message[]= {"Access Granted"};
	unsigned char message1[]= {"Access denied!"};
	unsigned char message2[]= {"Activated!"};
	unsigned char message3[]= {"Deactivated!"};
	unsigned int c[]={0x30,0x30,0x01,0x06,0x0e,0x80};
	unsigned int i,j;
	PINSEL0=0X00000000;
	IO0DIR=0x00000ffc;
	for(i=0;i<6;i++)
	{
		command(c[i]);
		delay1(65000);
	}
	while(1)
	{
		command(0x80);
		delay1(65000);
		for(j=0;j<14;j++)
		{
			if(x==1){
			data(message[j]);
			delay1(65000);
			}
			else if(x==2){
				data(message1[j]);
			delay1(65000);
			}
			else if(x==3){
				data(message2[j]);
			delay1(65000);
			}
			else if(x==4){
				data(message3[j]);
			delay1(65000);
			}
		}
		delay1(10000);
		command(0x01);
		delay1(10000);
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
	delay1(2000);
	IO0CLR=0x00000008;
	y=x;
	y=y & 0x0f;
	y=y<<4;
	IO0CLR=0x00000004;
	IO0SET=y;
	IO0SET=0x00000008;
	delay1(2000);
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
	delay1(100);
	b=a;
	b=b& 0xf0;
	b=b<<4;
	IO0CLR=0x000000fc;
	IO0SET=0x00000004;
	IO0SET=b;
	IO0SET=0x00000008;
	delay1(100);
	IO0CLR=0x00000008;
}

void delay1(unsigned int x)
{
	unsigned int i;
	for(i=0;i<x;i++);
}