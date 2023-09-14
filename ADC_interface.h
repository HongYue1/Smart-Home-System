#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

// Enumeration for ADC channel names
typedef enum
{
    channel0, // Channel 0
    channel1, // Channel 1
    channel2, // Channel 2
    channel3, // Channel 3
    channel4, // Channel 4
    channel5, // Channel 5
    channel6, // Channel 6
    channel7  // Channel 7
} ChannelName;

// Function to initialize ADC
void ADC_VidInit();

// Function to read ADC channel synchronously
u16 ADC_u16ReadChannelSyn(u8 Copy_u8Channel);

#endif
