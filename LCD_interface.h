#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

// Sends a command to the LCD
void LCD_voidSendCommand(u8 Copy_u8Command);

// Sends data to be displayed on the LCD
void LCD_voidSendData(u8 Copy_u8Data);

// Initializes the LCD
void LCD_voidInit(void);

// Sends a string to be displayed on the LCD
void LCD_voidSendString(char *str);

// Moves the cursor to the specified row and column on the LCD
void LCD_voidGoToRowColumn(unsigned char Row, unsigned char Column);

// Prints a number on the LCD
void LCD_voidPrintNumber(int num);

// Defines and sends an extra custom character to the LCD
struct Extra_Character
{
    u8 *copy_u8Pattern;
    u8 copy_u8PatternNumber;
    u8 copy_u8Row;
    u8 copy_u8Column;
};
void LCD_voidSendExtraChar(struct Extra_Character copy_character);

// Reads data from the LCD
void LCD_voidReadData(u8 *data);

// Deletes the last character displayed on the LCD
void LCD_voidDeleteLastCharacter(void);

// Clears the entire screen of the LCD
void LCD_voidClearScreen();

#endif
