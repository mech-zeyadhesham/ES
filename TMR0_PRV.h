// GUARD
#ifndef _TMR_PRV_H
#define _TMR_PRV_H

#define TCCR0    		*((volatile u8*) 0x53 )
#define TCNT0   		*((volatile u8*) 0x52 )
#define OCR0      		*((volatile u8*) 0x3C )
#define TIMSK         	*((volatile u8*) 0x39 )
#define TIFR              *((volatile u8*) 0x38 )
#define LED               *((volatile u8*) 0x3B )

#endif



