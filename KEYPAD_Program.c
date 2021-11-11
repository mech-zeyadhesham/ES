#include "../../LIB/STD_TYPES.h"
#include "util/delay.h"

#include "../../MCAL/DIO/V1/MDIO_Interface.h"
#include "KEYPAD_Interface.h"
# define KPD_PORT   PORTA
/*INITIALIZATION*/
void HKPD_VoidInit(void)
{

	/* putting the first 4 pins (Rows) as inputs and the second 4 pins (Columns) as outputs */

   MDIO_VoidSetPortDirection(KPD_PORT , 0b11110000);

	/* Setting the default value for all the keypad pins as high */

   MDIO_VoidSetPortValue(KPD_PORT ,0b11111111);

}
u8 HKPD_GetU8pressedkey(void)
{
	
	u8 Copy_pressedkey=50;
	u8 Copy_U8Column;
	u8 Copy_U8Row;
	u8 Copy_ReturnValue;
	/* Columns loop */
for (Copy_U8Column=0;Copy_U8Column<4;Copy_U8Column++)
{
	/* Instruction to set one column only as low at each step */
MDIO_VoidSetPinValue(PORTA,4+Copy_U8Column,LOW);
/* Rows loop */
for(Copy_U8Row=0 ; Copy_U8Row<4 ;Copy_U8Row++)
{
	/* loop for checking which row will give a zero value as a switch has been pressed */

	Copy_ReturnValue=MDIO_U8GetPinValue(PORTA, Copy_U8Row);
/* Algorithm to get which switch has been pressed (Intersection of rows and columns) */

     if(0==Copy_ReturnValue)
{
	Copy_pressedkey=(4*Copy_U8Row)+Copy_U8Column+1;
	
}	
/* loop for waiting until the user stops pressing the switch */
       while (0==MDIO_U8GetPinValue(PORTA,Copy_U8Row))
  {
	
  }	
/* Delay to eliminate switch bouncing */
  _delay_ms(10);
}
/* To return the columns to default (high) again */
MDIO_VoidSetPinValue(PORTA,4+Copy_U8Column,HIGH);

	
}
	
	
return	Copy_pressedkey;
	
	
}
u8 HKPD_U8Calculator(void)
{
	
	u8 Copy_pressedkey=50;
	u8 Copy_U8Column;
	u8 Copy_U8Row;
	u8 Copy_ReturnValue;
	/* Columns loop */
for (Copy_U8Column=0;Copy_U8Column<4;Copy_U8Column++)
{
	/* Instruction to set one column only as low at each step */
MDIO_VoidSetPinValue(PORTA,4+Copy_U8Column,LOW);
/* Rows loop */
for(Copy_U8Row=0 ; Copy_U8Row<4 ;Copy_U8Row++)
{
	/* loop for checking which row will give a zero value as a switch has been pressed */

	Copy_ReturnValue=MDIO_U8GetPinValue(PORTA, Copy_U8Row);
/* Algorithm to get which switch has been pressed (Intersection of rows and columns) */

     if(0==Copy_ReturnValue)
{
	Copy_pressedkey=(4*Copy_U8Row)+Copy_U8Column+1;
	
}
switch(Copy_pressedkey)	
{
case 1: x=1  ; break;	
case 2: x=2  ; break;	
case 3: x=3  ; break;	
case 4: x=4  ; break;	
case 5: x=5  ; break;	
case 6: x=6  ; break;	
case 7: x=7  ; break;	
case 8: x=8  ; break;	
case 9: x=9  ; break;	
case 10: x=0  ; break;	
case 11: x='.'  ; break;	
case 12: x='='  ; break;	
case 13: x='*'  ; break;	
case 14: x='/' ; break;
case 15: x='+' ; break;	
case 16: x='-' ; break;			
	
	
	
}
/* loop for waiting until the user stops pressing the switch */
       while (0==MDIO_U8GetPinValue(PORTA,Copy_U8Row))
  {
	
  }	
/* Delay to eliminate switch bouncing */
  _delay_ms(10);
}
/* To return the columns to default (high) again */
MDIO_VoidSetPinValue(PORTA,4+Copy_U8Column,HIGH);

	
}
	
	
return	Copy_pressedkey;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
