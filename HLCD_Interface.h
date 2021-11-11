#include "../../LIB/STD_TYPES.h"
#ifndef _HLCD_INTERFACE_H
#define _HLCD_INTERFACE_H

void HLCD_VoidWriteSpecialCharacter(u8* Arr,u8 Copy_U8XPOS,u8 Copy_U8YPOS,u8 block_num);
void HLCD_VoidSendCharacter(u8 Copy_U8Data);
void HLCD_VoidSendCommand(u8 Copy_U8Command);
void HLCD_VoidInit(void);
void HLCD_VoidSendNumber(u32 num);

#endif 
