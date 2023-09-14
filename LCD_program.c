#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_PRIVATE.h"
#include "DIO_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include <util/delay.h>

#ifdef F_CPU
#undef F_CPU
#define F_CPU 1000000UL // for performance reasons in proteus
#endif

u8 Cursor_Postion = 0;

void LCD_voidSendCommand(u8 Copy_u8Command)
{
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, PinLow); // RS read command
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, PinLow); // RW write to LCD

    DIO_VidSetPortValue(LCD_DATA_PORT, Copy_u8Command); // put the data into the port

    // 2ms Pulse
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, PinHigh); // Enable on
    _delay_ms(2);                                          // wait 2ms
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, PinLow);  // Enable off
}

void LCD_voidSendData(u8 Copy_u8Data)
{
    if (Cursor_Postion == 16)
    {
        LCD_voidGoToRowColumn(1, 0);
    }

    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, PinHigh); // RS read Data
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, PinLow);  // RW write to LCD

    DIO_VidSetPortValue(LCD_DATA_PORT, Copy_u8Data); // put the data into the port

    // 2ms Pulse
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, PinHigh); // Enable on
    _delay_ms(2);                                          // wait 2ms
    DIO_VidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, PinLow);  // Enable off

    Cursor_Postion++;
}

void LCD_voidInit(void)
{
    DIO_VidSetPortDirection(LCD_DATA_PORT, Output);
    DIO_VidSetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, Output);
    DIO_VidSetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, Output);
    DIO_VidSetPinDirection(LCD_CTRL_PORT, LCD_E_PIN, Output);

    _delay_ms(15); // wait for VDD to reach 4.5V

    LCD_voidSendCommand(0x38); // 8-bit mode, 2 lines, 5x8 font (5x7 if with cursor)

    LCD_voidSendCommand(0x0C); // Display on, cursor off, blink off

    LCD_voidSendCommand(0x01); // Clears entire display and sets DDRAM address to 0x00.

    _delay_ms(2);
}

void LCD_voidSendString(char *str)
{
    // Send each character in the string to the LCD
    while (*str)
    {
        LCD_voidSendData(*str++);
    }
}

// address = (0x40 * y) + x, where 0x40 is the offset for the second line of the LCD.
void LCD_voidGoToRowColumn(unsigned char Row, unsigned char Column)
{
    // Calculate DDRAM address based on x and y coordinates
    unsigned char addr = (0x40 * Row) + Column;

    // Send command to set DDRAM address
    LCD_voidSendCommand(0x80 | addr);
    Cursor_Postion = Row * 16 + Column;
}

void LCD_voidPrintNumber(int num)
{
    char str[16];
    int i = 0;

    // Handle negative numbers
    if (num < 0)
    {
        str[i] = '-';
        i++;
        num = -num; // make it positive
    }

    // Convert each digit to a character
    do
    {
        str[i] = (num % 10) + 48; // 48 is the ascii for zero, I used it to change the number to a character
        i++;
        num /= 10;
    } while (num);

    // Reverse the string back to the right order since it was stored from LSD to the MSD
    int j = i - 1;
    for (int k = 0; k < i / 2; k++)
    {
        char temp = str[k];
        str[k] = str[j];
        str[j] = temp;
        j--;
    }

    // Display the string on the LCD
    LCD_voidSendString(str);
}

void LCD_voidSendExtraChar(struct Extra_Character copy_character)
{
    u8 CGRAM_address = 0, Iterator = 0;

    /*Calculate the CGRAM address, 8 blocks, each block is 8 bytes*/
    CGRAM_address = copy_character.copy_u8PatternNumber * 8;

    /*send the address to CGRAM using the command 0b01XX XXXX, since the maximum block is 7*8=56
    so the maximum value of the address is 0011 1000, we can just add 0b0100 0000 (64), to set the bit numnber 6 */

    LCD_voidSendCommand(CGRAM_address | 0b01000000);

    /*Write the pattern from to the CGRAM*/
    for (Iterator = 0; Iterator < 8; Iterator++)
    {
        LCD_voidSendData(copy_character.copy_u8Pattern[Iterator]);
    }

    /*go back to the DDRAM to dispaly data*/
    LCD_voidGoToRowColumn(copy_character.copy_u8Row, copy_character.copy_u8Column);

    /*Display the pattern written in the CGRAM by sending the block number (0->7)
    when we send a character to lCD like 'A', the microcontroller of the LCD looks the ASCII code
    of the 'A' in the CGROM, then display it, but the ASCII numbers from 0 to 7 are not used and kept
    clear to be used for CGRAM*/

    LCD_voidSendData(copy_character.copy_u8PatternNumber);
}

void LCD_voidDeleteLastCharacter(void)
{
    // Check if the cursor is not at the start of the LCD
    if (Cursor_Postion > 0)
    {
        // Move the cursor back one position
        Cursor_Postion--;
        LCD_voidGoToRowColumn(Cursor_Postion / 16, Cursor_Postion % 16);

        // Write a blank space to delete the character
        LCD_voidSendData(' ');

        // Move the cursor back one position again to be ready for the next character
        Cursor_Postion--;
        LCD_voidGoToRowColumn(Cursor_Postion / 16, Cursor_Postion % 16);
    }
}

void LCD_voidClearScreen()
{
    LCD_voidSendCommand(0x01);
    Cursor_Postion = 0;
}
