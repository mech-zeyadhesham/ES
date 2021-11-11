#include "../../LIB/STD_TYPES.h"

#include"../../LIB/BIT_MATH.h"
#include "util/delay.h"

#include "HLCD_Interface.h"
#include "HLCD_Private.h"
#include "../../MCAl/DIO/V1/MDIO_Interface.h"

#define LCD_FUNCTION_SET_CMD		(u8)0b00111000
#define LCD_DISPLAY_ON_CMD	        (u8)0b00001111
#define LCD_DISPLAY_CLEAR_CMD		(u8)0b00000001
#define LCD_ENTRY_MODE_SET_CMD		(u8)0b00000110
#define    FULL_OUTPUT              (u8)0b11111111


void HLCD_VoidSendCharacter(u8 Copy_U8Data)
{
	

MDIO_VoidSetPinValue(LCD_RS_PORT,  LCD_RS_PIN , HIGH);/*RS=1 TO GET DATA*/
MDIO_VoidSetPinValue(LCD_RW_PORT , LCD_RW_PIN , LOW);/*RW=0 AND Write on lcd*/
MDIO_VoidSetPortValue(LCD_DATA_PORT , Copy_U8Data);/*Set Data to data pins*/
MDIO_VoidSetPinValue(LCD_EN_PORT , LCD_EN_PIN ,LOW);/*ENABLE */
_delay_ms(1);
MDIO_VoidSetPinValue(LCD_EN_PORT , LCD_EN_PIN ,HIGH);
_delay_ms(1);
MDIO_VoidSetPinValue(LCD_EN_PORT , LCD_EN_PIN ,LOW);
_delay_ms(2);	


}

void HLCD_VoidSendCommand(u8 Copy_U8Command)
{
	
MDIO_VoidSetPinValue(LCD_RS_PORT,LCD_RS_PIN , LOW);/*RS=1 TO GET DATA*/
MDIO_VoidSetPinValue(LCD_RW_PORT,LCD_RW_PIN , LOW);/*RW=0 AND Write on lcd*/
MDIO_VoidSetPortValue(LCD_DATA_PORT,Copy_U8Command);/**/
MDIO_VoidSetPinValue(LCD_EN_PORT , LCD_EN_PIN ,LOW);/*ENABLE */
_delay_ms(1);
MDIO_VoidSetPinValue(LCD_EN_PORT , LCD_EN_PIN ,HIGH);
_delay_ms(1);
MDIO_VoidSetPinValue(LCD_EN_PORT , LCD_EN_PIN ,LOW);
_delay_ms(2);	
	
	
}

void HLCD_VoidSendString(char* Copy_String)
{
	       u8 x=0;
/*we use the while loop as we not know the number of iterations but know the end of loop is '\0'*/
	while(Copy_String[x]!='\0')
	{    /*get the function to send the character*/
		HLCD_VoidSendCharacter(Copy_String[x]);
	 /*to increment as a counter and print the next character */
		x++;
	}

}

void HLCD_VoidSetPosition(u8 Copy_U8XPOS,u8 Copy_U8YPOS)
{
	  u8 local_U8Address;
	  /*i check the x position*/
      if (Copy_U8XPOS==0)
      {
    	  /*put the address in the first line */
    	  local_U8Address=Copy_U8YPOS;
      }
      else if (Copy_U8XPOS==1)
      {
    	  /*put the address in the second  line */
    	  local_U8Address=Copy_U8YPOS+0x40;
      }
    /*set the bit number 8 to set the DDRAM Address command and send command */
      HLCD_VoidSendCommand(local_U8Address+128);


}
/*function to WriteSpecialCharacter or any thing */
void HLCD_VoidWriteSpecialCharacter(u8* Arr,u8 Copy_U8XPOS,u8 Copy_U8YPOS,u8 block_num)
{

u8 CGRAMAddress= block_num*8;
HLCD_VoidSendCommand(CGRAMAddress+64);
for (u8 i=0;i<8;i++)
{
	HLCD_VoidSendCharacter( Arr[i]);

}
HLCD_VoidSetPosition( Copy_U8XPOS,Copy_U8YPOS);
HLCD_VoidSendCharacter(block_num );

}
/*function to send value of variable */
void HLCD_VoidSendNumber(u32 num)
{
u32 rev=1;
while(num>0)
{
rev=((rev*10)+(num%10));
num=num/10;

}
while(rev>1)
{
u32 n=(rev %10);
HLCD_VoidSendCharacter(n+48);
rev=(rev/10);

}

}




void HLCD_VoidInit(void)/*INITIALIZATION*/
{
	
	
	MDIO_VoidSetPortDirection(LCD_DATA_PORT , FULL_OUTPUT);
	MDIO_VoidSetPinDirection(LCD_RS_PORT , LCD_RS_PIN,OUTPUT);
	MDIO_VoidSetPinDirection(LCD_RW_PORT , LCD_RW_PIN,OUTPUT);
	MDIO_VoidSetPinDirection(LCD_EN_PORT , LCD_EN_PIN,OUTPUT);
	/*wait for more than 30ms after vDD rises to 4.5v*/
	_delay_ms(40);
	/*we use the function set : send command as RS=0 and r/w=0*/

	HLCD_VoidSendCommand(LCD_FUNCTION_SET_CMD);/*f is font  =0 (5x8),n is number of lines =1(2-line)*/
	_delay_ms(1);/*wait for more than 39 us*/
	/*Display on off control: display enable, disable cursor, no blink cursor*/

	HLCD_VoidSendCommand(LCD_DISPLAY_ON_CMD);/*D=1 ON,C=1 ,B=0 is constant*/
	_delay_ms(1);/*wait for more than 39 us*/
	/*Clear display*/

	HLCD_VoidSendCommand(LCD_DISPLAY_CLEAR_CMD);
	_delay_ms(2);/*wait for more than 39 us*/

	
	


}
