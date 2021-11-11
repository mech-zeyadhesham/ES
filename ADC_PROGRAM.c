#include "../../LIb/STD_TYPES.h"
#include "ADC_REGISTERS.h"
#include "MDIO_Interface.h"
#include "BITMATH.h"
//ERROR VALIDATION ADD
#define CH_NUM 0    //MACRO TO SWITCH CHANNEL OF ADC


//INITIALIZATION 

void ADC_Init(void)
{
	//    Select Channel
	
	  //==Default ADC0
	CLR_BIT(ADMUX, 0);
	CLR_BIT(ADMUX, 1);
	CLR_BIT(ADMUX, 2);
	CLR_BIT(ADMUX, 3);

	//    Select Single Conversion
	
	//    Select ADCLR = 0
	CLR_BIT(ADMUX, 5);
	//    Set Prescaler = 64
	SET_BIT(ADCSRA, 2);
	SET_BIT(ADCSRA, 1);
	CLR_BIT(ADCSRA, 0);
	//    Select VREF = AVCC 
	SET_BIT(ADMUX, 6); //AVCC with external capacitor at AREF pin
	//    ADC ENABLE
	//SET_BIT(ADCSRA, 7);     //in free-runnng mode only set 
}

// READ ADC 

u16 ADC_Read(CH_NUM)
{
	//Start Conversion
	
	SET_BIT(ADCSRA, 6);
	while (GET_BIT(ADCSRA,CH_NUM) == 0) // WAITING the flag to be fired and check it i a volatile 
	{
		
	}
	SET_BIT(ADCSRA, 4);
	
	//Return the bits that hold the ADC conversion result which stored in ADC_DATA
	
	return ADC_DATA;
}
