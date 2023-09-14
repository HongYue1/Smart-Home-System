#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

// Defines for TIMER0

// Address of Timer/Counter0 Register - used to count the Timer/Counter increments
#define TCNT0 *((volatile u8 *)0x52)

// Address of timer0 control register - used to control various aspects of Timer0
#define TCCR0 *((volatile u8 *)0x53)

// Define Waveform generation mode bit0 (WGM00) in TCCR0 - can be used to set normal or CTC mode
#define TCCR0_WGM00 6

// Define Waveform generation mode bit1 (WGM01) in TCCR0 - can be used to set normal or CTC mode
#define TCCR0_WGM01 3

// Define prescaler bit0 (CS00) in TCCR0 - Sets the prescaler for Timer0
#define TCCR0_CS00 0

// Define prescaler bit1 (CS01) in TCCR0 - Sets the prescaler for Timer0
#define TCCR0_CS01 1

// Define prescaler bit2 (CS02) in TCCR0 - Sets the prescaler for Timer0
#define TCCR0_CS02 2

// Address of output compare register 0 (OCR0) - used for output compare function
#define OCR0 *((volatile u8 *)0x5c)

// Address of timer interrupt mask register(TIMSK) - controls which interrupts are enabled
#define TIMSK *((volatile u8 *)0x59)

// Define for enabling output compare interrupt (OCIE0) in TIMSK
#define TIMSK_OCIE0 1

// Define for enabling overflow interrupt (TOIE0) in TIMSK
#define TIMSK_TOIE0 0

// Define compare output mode bit1 (COM01) in TCCR0 - Sets how OC0 reacts when a compare match occurs
#define TCCR0_COM01 5

// Define compare output mode bit0 (COM00) in TCCR0 - Sets how OC0 reacts when a compare match occurs
#define TCCR0_COM00 4

#endif
