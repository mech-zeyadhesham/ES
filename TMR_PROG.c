#include "../../LIb/STD_TYPES.h"
#include "ADC_REGISTERS.h"
#include "MDIO_Interface.h"
#include "BITMATH.h"

void TMR0_INIT(void)
{
//select Normal Mode
CLR_BIT(TCCR0,6);
CLR_BIT(TCCR0,3);
//Select Prescaller
SET_BIT(TCCR0,2);
CLR_BIT(TCCR0,1);
CLR_BIT(TCCR0,0);
//Enable PIE
SET_BIT(TIMSK,0);
//TCNT0
TCNT0 = TCCR0 & 0b01110110; //PRELOAD to 238
}


void __vector_11 (void) __attribute__((single))
{
	static ov_count;
	ov_count++;
	if (ov_count == 123)
	{
		TCNT0 = 238;
		SET_BIT(LED,0);
		MDIO_VoidTogBitValue(PORTA,0);
		ov_count = 0;
		
	}
}

