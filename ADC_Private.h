#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

// ADMUX Register Address
#define ADMUX *((volatile u8 *)0x27)

// ADCSRA Register Address
#define ADCSRA *((volatile u8 *)0x26)

// ADCL_H Register Address
#define ADCL_H *((volatile u16 *)0x24)

#endif
