#include"../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"
#include "../../../MCAL/DIO/V1/MDIO_Interface.h"
#include "../../../MCAL/DIO/V1/MDIO_Private.h"


void MDIO_VoidSetPinDirection(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Dir)
{
	if(1==Copy_U8Dir)
	{
		switch(Copy_U8Port)
		{
			case 0 :SET_BIT(DDRA_REG,Copy_U8Pin);break;
			case 1 :SET_BIT(DDRB_REG,Copy_U8Pin);break;
			case 2 :SET_BIT(DDRC_REG,Copy_U8Pin);break;
			case 3 :SET_BIT(DDRD_REG,Copy_U8Pin);break;
		
			
		}
		
	}
	else if(0==Copy_U8Dir)
	{
		switch(Copy_U8Port)
		{
		
			case 0 :CLR_BIT(DDRA_REG,Copy_U8Pin);break;
			case 1 :CLR_BIT(DDRB_REG,Copy_U8Pin);break;
			case 2 :CLR_BIT(DDRC_REG,Copy_U8Pin);break;
			case 3 :CLR_BIT(DDRD_REG,Copy_U8Pin);break;
		}
		
	}
	else
	{
		/*
		Do Nothing
		*/
	}
}

void MDIO_VoidSetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Value)
{
	if(1==Copy_U8Value)
	{
		switch(Copy_U8Port)
		{
			case 0:SET_BIT(PORTA_REG,Copy_U8Pin);break;
			case 1:SET_BIT(PORTB_REG,Copy_U8Pin);break;
			case 2:SET_BIT(PORTC_REG,Copy_U8Pin);break;
			case 3:SET_BIT(PORTD_REG,Copy_U8Pin);break;
		}
	}
	
	else if(0==Copy_U8Value)
	{
		switch(Copy_U8Port)
		{
			case 0:CLR_BIT(PORTA_REG,Copy_U8Pin);break;
			case 1:CLR_BIT(PORTB_REG,Copy_U8Pin);break;
			case 2:CLR_BIT(PORTC_REG,Copy_U8Pin);break;
			case 3:CLR_BIT(PORTD_REG,Copy_U8Pin);break;
		}
	}
	
}

u8 MDIO_U8GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin)
{
	u8 LOC_U8Value;
	switch(Copy_U8Port)
	{
		case 0:LOC_U8Value=GET_BIT(PINA_REG,Copy_U8Pin);break;
		case 1:LOC_U8Value=GET_BIT(PINB_REG,Copy_U8Pin);break;
		case 2:LOC_U8Value=GET_BIT(PINC_REG,Copy_U8Pin);break;
		case 3:LOC_U8Value=GET_BIT(PIND_REG,Copy_U8Pin);break;		
	}
	return LOC_U8Value;
	
}

void MDIO_VoidSetPortDirection(u8 Copy_U8Port,u8 Copy_U8Dir)
{    
	switch(Copy_U8Port)
	{
		case 0:DDRA_REG=Copy_U8Dir;break;
		case 1:DDRB_REG=Copy_U8Dir;break;
		case 2:DDRC_REG=Copy_U8Dir;break;
		case 3:DDRD_REG=Copy_U8Dir;break;		
	}
		
}

void MDIO_VoidSetPortValue(u8 Copy_U8Port,u8 Copy_U8Value)
{
	switch(Copy_U8Port)
	{
		case 0:PORTA_REG=Copy_U8Value;break;
		case 1:PORTB_REG=Copy_U8Value;break;
		case 2:PORTC_REG=Copy_U8Value;break;
		case 3:PORTD_REG=Copy_U8Value;break;		
	}
	
	
}
void MDIO_VoidTogPinValue(u8 Copy_U8Port,u8 Copy_U8Pin)
{
	switch(Copy_U8Port)
	{
		case 0:TOG_BIT(PORTA_REG,Copy_U8Pin); break;
		case 1:TOG_BIT(PORTB_REG,Copy_U8Pin);break;
		case 2:TOG_BIT(PORTC_REG,Copy_U8Pin);break;
		case 3:TOG_BIT(PORTD_REG,Copy_U8Pin);break;		
	}
	
	
	
	
}



