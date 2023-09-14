#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "TIMER_INTERFACE.h"
#include "TIMER_PRIVATE.h"

#ifdef F_CPU
#undef F_CPU
#define F_CPU 1000000UL // for performance reasons in proteus
#endif

// Function to Initialize TIMER0 with given mode and prescaler
void TIMER0_Vid_Init(et_TIMER0MODE mode, et_TIMER0PRESSCAELER prescaler)
{
	// Setting the Timer0 mode (i.e., Normal, CTC, FastPWM, PhaseCorrect modes)
	switch (mode)
	{
	case TIMER0_NORMAL_MODE:
		// For Normal Mode, clear WGM00 & WGM01 bits in TCCR0 register
		Clear_bit(TCCR0, TCCR0_WGM00);
		Clear_bit(TCCR0, TCCR0_WGM01);
		break;

	case TIMER0_CTC_MODE:
		// For CTC Mode, clear WGM00 and set WGM01 bit in TCCR0 register
		Clear_bit(TCCR0, TCCR0_WGM00);
		Set_bit(TCCR0, TCCR0_WGM01);
		break;

	case TIMER0_FASTPWM_MODE:
		// For Fast PWM Mode, set both WGM00 & WGM01 bits in TCCR0 register
		Set_bit(TCCR0, TCCR0_WGM00);
		Set_bit(TCCR0, TCCR0_WGM01);
		break;

	case TIMER0_PHASECORRECT_MODE:
		// For Phase Correct PWM Mode, set WGM00 and clear WGM01 bit in TCCR0 register
		Set_bit(TCCR0, TCCR0_WGM00);
		Clear_bit(TCCR0, TCCR0_WGM01);
		break;
	}

	// Setting up the prescaler
	TCCR0 = TCCR0 & 0xf8;	   // Masking the first 3 bits of TCCR0 because these bits are used for prescaler
	TCCR0 = TCCR0 | prescaler; // Setting the prescaler value
}

// Function to set the comparison match value on TIMER0
void TIMER0_Vid_SetCompMatchValue(u8 value)
{
	OCR0 = value; // Set Output Compare Register 0 (OCR0) to input value
}

// Function to set Fast PWM mode on TIMER0
void TIMER0_Vid_SetFpwm_Mode(et_TIMER0FPWM mode)
{
	switch (mode)
	{
	case inverted:
		// If mode is inverted, set COM00 and COM01 bits in TCCR0 register
		Set_bit(TCCR0, TCCR0_COM01);
		Set_bit(TCCR0, TCCR0_COM00);
		break;

	case non_inverted:
		// If mode is non-inverted, set COM01 and clear COM00 bit in TCCR0 register
		Set_bit(TCCR0, TCCR0_COM01);
		Clear_bit(TCCR0, TCCR0_COM00);
		break;
	}
}

// Function to enable TIMER0 interrupt
void TIMER0_Interrupt_Enable()
{
	Set_bit(TIMSK, TIMSK_TOIE0); // Set TOIE0 bit in TIMSK register to enable TIMER0 interrupt
}

// Function to disable TIMER0 interrupt
void TIMER0_Interrupt_Disable()
{
	Clear_bit(TIMSK, TIMSK_TOIE0); // Clear TOIE0 bit in TIMSK register to disable TIMER0 interrupt
}

void FAST_PWM_NON_INVERTED_INIT()
{												  // PWM initalize
	DIO_VidSetPinDirection(Port_B, Pin1, Output); // for Power
	DIO_VidSetPinDirection(Port_B, Pin3, Output); // for Enable

	TIMER0_Vid_Init(TIMER0_FASTPWM_MODE, clk_1024_prescaler);
	TIMER0_Vid_SetFpwm_Mode(non_inverted);
	// end of timer
}