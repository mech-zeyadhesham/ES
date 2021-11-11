#ifndef _MDIO_INTERFACE_H
#define _MDIO_INTERFACE_H

/* Port Defines */
#define PORTA    0
#define PORTB    1
#define PORTC    2
#define PORTD    3

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* PIN Directions */
#define INPUT  0
#define OUTPUT 1

/* PIN Value Options */
#define HIGH   1
#define LOW    0




void MDIO_VoidSetPinDirection(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Dir);
void MDIO_VoidSetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_U8Value);
u8 MDIO_U8GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin);
void MDIO_VoidSetPortDirection(u8 Copy_U8Port,u8 Copy_U8Dir);
void MDIO_VoidSetPortValue(u8 Copy_U8Port,u8 Copy_U8Value);
void MDIO_VoidTogBitValue(u8 Copy_U8Port,u8 Copy_U8Pin);

#endif 
