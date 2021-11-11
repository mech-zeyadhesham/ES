// GUARD
#ifndef _ADC_REGISTERS_H
#define _ADC_REGISTERS_H

#define ADMUX    		*((volatile u8*) 0x27 )
#define ADCSRA   		*((volatile u8*) 0x26 )
#define ADCH      		*((volatile u8*) 0x25 )
#define ADCL         	*((volatile u8*) 0x24 )
#define ADC_DATA     *((volatile u16*) 0x24 )
#define SFIRO    	    *((volatile u8*) 0x50 )



#endif



