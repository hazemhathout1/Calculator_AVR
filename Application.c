/*
 * Application.c
 *
 *  Created on: Aug 20, 2023
 *      Author: hazem
 */

#include "Application.h"

uint8 value;
uint8 num1=ZERO_INIT;
uint8 num2=ZERO_INIT;
uint8 sym;
uint8 flag=1;
uint8 equal;
uint8 l_col=ZERO_INIT;
uint32 val;
uint8 col=1;
uint8 keypressed;


int main()
{
	Application_initialize();
	while(1)
	{
		flag=1;
		do{
			do{
				keypad_get_value(&keypad1,&value,&keypressed);
			}while(keypressed==KEY_NOT_PRESSED);
			if(((value!='/')&&(value!='+')&&(value!='-')&&(value!='*')))
			{
				num1=num1*10+value;
				lcd_4bit_send_int_pos(&lcd1,1,1,num1);
				col++;
			}
			else
			{
				flag=0;
			}
		}while((flag==1));
		/* -------------------------------- */
		lcd_4bit_send_char_data_pos(&lcd1,1,col++,value);
		sym=value;
		lcd_4bit_send_string_pos(&lcd1,2,1,"");
		flag=1;
		l_col=col;
		do{
		do{
			keypad_get_value(&keypad1,&value,&keypressed);
		}while(keypressed==KEY_NOT_PRESSED);
		if(((value!='/')&&(value!='+')&&(value!='-')&&(value!='*')&&(value!='=')))
		{
			num2=num2*10+value;
			lcd_4bit_send_int_pos(&lcd1,1,l_col,num2);
			col++;
		}
		else
		{
			flag=0;
		}
		}while((flag==1));
		lcd_4bit_send_char_data_pos(&lcd1,1,col++,value);

		if(sym=='+')
		{
			val=num1+num2;
			lcd_4bit_send_int_pos(&lcd1,1,col,val);
		}
		else if(sym=='-')
		{
			val=num1-num2;
			lcd_4bit_send_int_pos(&lcd1,1,col,val);
		}
		else if(sym=='*')
		{
			val=num1*num2;
			lcd_4bit_send_int_pos(&lcd1,1,col,val);
		}
		else if(sym=='/')
		{
			val=num1/num2;
			lcd_4bit_send_int_pos(&lcd1,1,col,val);
		}
	}

}

void Application_initialize()
{
	ecu_layer_initialize();
}



