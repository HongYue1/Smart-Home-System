#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

#define KPD_PORT Port_C

#define KPD_COL1PIN Pin0
#define KPD_COL2PIN Pin1
#define KPD_COL3PIN Pin2
#define KPD_COL4PIN Pin3

#define KPD_ROW1PIN Pin4
#define KPD_ROW2PIN Pin5
#define KPD_ROW3PIN Pin6
#define KPD_ROW4PIN Pin7

#define KPD_Column_Number 4
#define KPD_Row_Number 4

#define KPD_NOT_Pressed 0xff

#define KPD_Arr                                                                                  \
    {                                                                                            \
        {'7', '8', '9', '/'}, {'4', '5', '6', '*'}, {'1', '2', '3', '-'}, { 'C', '0', '=', '+' } \
    }

#endif