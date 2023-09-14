#ifndef LM35_ADC_H
#define LM35_ADC_H

int LM35_ADC_Get_Temp();

void LM35_Motor_Buzzer(); // update system status every time it's called
void Buzzer_init();       // buzzer pin direction

#endif