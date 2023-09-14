#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "DIO_interface.h"
#include "LDR_interface.h"

#ifdef F_CPU
#undef F_CPU
#define F_CPU 1000000UL // for performance reasons in proteus
#endif

/**
 * ?Control the intensity of the light automatically based on the analog input value.
 *
 * This function reads the value from an analog channel using the ADC module and calculates the percentage of the value relative to the maximum value (1024).
 * It then controls a pin on Port B of the microcontroller based on the calculated percentage.
 * If the percentage is greater than 50, the pin is set to high (PinHigh), otherwise it is set to low (PinLow).
 */

void AutoLightIntensity()
{
    u16 value = ADC_u16ReadChannelSyn(channel1); // Read the value from analog channel 1

    u8 percentage = 100 - (((float)value / 1024) * 100); // Calculate the percentage of the value

    if (percentage > 50)
    {
        light_state = 1;
        DIO_VidSetPinValue(Port_B, Pin2, PinHigh); // Set pin B2 to high if the percentage is greater than 50
    }
    else
    {
        light_state = 0;
        DIO_VidSetPinValue(Port_B, Pin2, PinLow); // Set pin B2 to low if the percentage is less than or equal to 50
    }
}