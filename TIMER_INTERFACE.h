#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

// Enumeration for Timer0 modes
typedef enum
{
	TIMER0_NORMAL_MODE = 0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE
} et_TIMER0MODE;

// Enumeration for Timer0 prescaler options
typedef enum
{
	No_clock_source = 0,
	No_prescaling,
	clk_8_prescaler,
	clk_64_prescaler,
	clk_256_prescaler,
	clk_1024_prescaler,
	External_clock_fallingedge,
	External_clock_risingedge
} et_TIMER0PRESSCAELER;

// Enumeration for Timer0 Fast PWM mode options
typedef enum
{
	inverted,
	non_inverted
} et_TIMER0FPWM;

// Function to initialize Timer0 with specified mode and prescaler
void TIMER0_Vid_Init(et_TIMER0MODE mode, et_TIMER0PRESSCAELER presscaler);

// Function to set the compare match value for Timer0
void TIMER0_Vid_SetCompMatchValue(u8 value);

// Function to set the Fast PWM mode for Timer0
void TIMER0_Vid_SetFpwm_Mode(et_TIMER0FPWM mode);

// Function to enable Timer0 interrupts
void TIMER0_Interrupt_Enable();

// Function to disable Timer0 interrupts
void TIMER0_Interrupt_Disable();

// Function to initialize Timer0 in Fast PWM non-inverted mode
void FAST_PWM_NON_INVERTED_INIT();

#endif
