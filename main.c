#ifdef F_CPU
#undef F_CPU
#define F_CPU 1000000UL // for performance reasons in proteus
#endif

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "Keypad_config.h"
#include "Keypad_interface.h"
#include "ADC_interface.h"
#include "LM35_ADC.h"
#include "LDR_interface.h"
#include "TIMER_INTERFACE.h"
#include "House_System.h"

#include <util/delay.h> //for delays
#include <string.h>     // For the strcmp function

int main()
{
  House_init(); // initialize all components

  // Display the "House System" message
  LCD_voidSendString("House System");
  _delay_ms(400);
  LCD_voidClearScreen();

  // call the system
  houseSystem();

  return 0;
}
