#ifndef MBED_TEXTLCD_H
#define MBED_TEXTLCD_H

#include "mbed.h"

class TextLCD : public Stream {

public:

	/** Create a TextLCD interface
     *
     * @param rs    Instruction/data control line
     * @param e     Enable line (clock)
     * @param d0-d3 Data lines
     * @param type  Sets the panel size/addressing mode (default = LCD16x2)
     */
    TextLCD(PinName rs, PinName e, PinName d0, PinName d1, PinName d2, PinName d3);

#if DOXYGEN_ONLY
    /** Write a character to the LCD
     *
     * @param c The character to write to the display
     */
    int putc(int c);

    /** Write a formated string to the LCD
     *
     * @param format A printf-style format string, followed by the
     *               variables to use in formating the string.
     */
    int printf(const char* format, ...);
#endif

    /** Locate to a screen column and row
     *
     * @param column  The horizontal position from the left, indexed from 0
     * @param row     The vertical position from the top, indexed from 0
     */
    void locate(int column, int row);

    /** Clear the screen and locate to 0,0 */
    void cls();

    int rows();
    int columns();



    // Stream implementation functions
    virtual int _putc(int value);
    virtual int _getc();

    int  address(int column, int row);
    void character(int column, int row, int c);
    void writeByte(int value);
    void writeCommand(int command);
    void writeData(int data);
	void createChar(uint8_t location, uint8_t charmap[]) ;
	
protected:
    DigitalOut m_rs, m_e;
    BusOut m_d;

    int m_column;
    int m_row;
};

#endif
