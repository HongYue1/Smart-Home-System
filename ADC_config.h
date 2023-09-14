#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

// ADMUX Register Configuration
#define ADMUX_REFS1 7 // Reference Selection Bit 1
#define ADMUX_REFS0 6 // Reference Selection Bit 0
#define ADMUX_ADLAR 5 // ADC Left Adjust Result

// ADCSRA Register Configuration
#define ADCSRA_ADEN 7  // ADC Enable
#define ADCSRA_ADSC 6  // ADC Start Conversion
#define ADCSRA_ADATE 5 // ADC Auto Trigger Enable
#define ADCSRA_ADIF 4  // ADC Interrupt Flag
#define ADCSRA_ADIE 3  // ADC Interrupt Enable

/* Clock Prescaler Configuration */
#define ADCSRA_ADPS2 2 // ADC Prescaler Bit 2
#define ADCSRA_ADPS1 1 // ADC Prescaler Bit 1
#define ADCSRA_ADPS0 0 // ADC Prescaler Bit 0

/* Channel Configuration */
#define channel0 0b00000 // ADC Channel 0
#define channel1 0b00001 // ADC Channel 1
#define channel2 0b00010 // ADC Channel 2
#define channel3 0b00011 // ADC Channel 3
#define channel4 0b00100 // ADC Channel 4
#define channel5 0b00101 // ADC Channel 5
#define channel6 0b00110 // ADC Channel 6
#define channel7 0b00111 // ADC Channel 7

/* Prescaler Configuration */
#define PRE_SCALER_VALUE 128 // ADC Clock Prescaler Value

#endif
