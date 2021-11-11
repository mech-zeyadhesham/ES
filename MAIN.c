#include  "HAL/HLCD/HLCD_Interface.h"
#include "LIB/STD_TYPES.h"
#include<avr/delay.h>

void main(void)
{


	HLCD_VoidInit();

/*u8 pattern[8]={0b00010001,0b00010001,0b00010001,0b00011111,0b00011111,0b00000000,0b00000110};*/
	u8 pattern[8]={0b00000000,0b00000000,0b00001010,0b00000000,0b00000100,0b00001010,0b00010001};
      HLCD_VoidWriteSpecialCharacter(pattern,0,1,0);
    /*  HLCD_VoidSendNumber(12);*/

	/*HLCD_VoidSetPosition(0,1);
	HLCD_VoidSendString("aya");
	 _delay_ms(2000);
	 HLCD_VoidSetPosition(1,7);
	HLCD_VoidSendString("aya");
	 _delay_ms(2000);
	 HLCD_VoidSetPosition(0,12);
	 HLCD_VoidSendString("aya");
	 _delay_ms(2000);
	 */
	/*HLCD_VoidSendCharacter('A');
	_delay_ms(700);
	HLCD_VoidSendCharacter('Y');
	_delay_ms(700);
	HLCD_VoidSendCharacter('a');
	_delay_ms(700);
	HLCD_VoidSendCharacter('_');
	_delay_ms(700);
	HLCD_VoidSendCharacter('M');
	_delay_ms(700);
	HLCD_VoidSendCharacter('o');
	_delay_ms(700);
	HLCD_VoidSendCharacter('h');
	_delay_ms(700);
	HLCD_VoidSendCharacter('a');
	_delay_ms(700);
	HLCD_VoidSendCharacter('m');
	_delay_ms(700);
	HLCD_VoidSendCharacter('e');
	_delay_ms(700);
	HLCD_VoidSendCharacter('d');
*/
while(1)
	{

	}
}
