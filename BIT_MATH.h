#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(PORT,BITNO) ((PORT)|=  (1 << (BITNO)))
#define CLR_BIT(PORT,BITNO) ((PORT)&= ~(1 << (BITNO)))
#define TOG_BIT(PORT,BITNO) ((PORT)^=  (1 << (BITNO)))
#define GET_BIT(PORT,BITNO) (((PORT) >> (BITNO)) & 1)


#endif
