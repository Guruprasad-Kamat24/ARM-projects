#include<lpc21xx.h>

void delay()
{
unsigned int i;
for(i=0;i<10000;i++);
}

void serial()
{
  PINSEL0=0X00000005;
  U0LCR= 0X83;
  U0DLL=0X186;
  U0LCR=0X03;
}
