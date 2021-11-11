#ifndef _MDIO_PRIVATE_H
#define _MDIO_PRIVATE_H


#define DDRA_REG *((u8*)0x3a) 
#define DDRB_REG *((u8*)0x37)
#define DDRC_REG *((u8*)0x34)
#define DDRD_REG *((u8*)0x31)


#define PORTA_REG  *((u8*)0x3b)
#define PORTB_REG  *((u8*)0x38)
#define PORTC_REG  *((u8*)0x35)
#define PORTD_REG  *((u8*)0x32)
            
#define PINA_REG *((u8*)0x39)
#define PINB_REG *((u8*)0x36)
#define PINC_REG *((u8*)0x33)
#define PIND_REG *((u8*)0x30)


#endif


//VOLATILE to prevent caching, everytime reads the value and never use cached one