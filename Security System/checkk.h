#include<lpc21xx.h>
//#include "i2c.h"
void delay(void);
void buzzer(void);
void lcd(int);
void step(void);
void check1()
{
  unsigned char msg1[]={" No Entry!"};
  unsigned int i;
   for(i=0;i<12;i++)
  {
     while(!(U0LSR & 0x20));
      U0THR=msg1[i];
  }
	buzzer(); 
	 lcd(2);
	
    //calling buzzer
}

void check(int x)
{
  unsigned char msg[]={" You Are Welcome!"};
  unsigned int i;
 if(x==527)
 {
    for(i=0;i<17;i++)
    {
      while(!(U0LSR & 0x20));
       U0THR=msg[i];
    }  
		
			delay();	delay();	delay();
		step(); //calling stepper
    //i2c();
    delay(); delay();// calling lcd		
		lcd(1);// calling lcd 
    
 }
}
