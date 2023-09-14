#ifndef BIT_MATH_H
#define BIT_MATH_H

#define Set_bit(var, bit) var |= (1 << bit)
#define Clear_bit(var, bit) var &= ~(1 << bit)
#define Toggle_bit(var, bit) var ^= (1 << bit)
#define Get_bit(var, bit) ((var >> bit) & 1)

#endif