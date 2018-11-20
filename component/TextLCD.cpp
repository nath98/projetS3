#include "TextLCD.h"
#include "mbed.h"

TextLCD::TextLCD(PinName rs, PinName e, PinName d0, PinName d1,PinName d2, PinName d3) : m_rs(rs),m_e(e), m_d(d0, d1, d2, d3)
{
    m_e  = 1;
    m_rs = 0;            // command mode

    wait(0.015);        // Wait 15ms to ensure powered up

    // send "Display Settings" 3 times (Only top nibble of 0x30 as we've got 4-bit bus)
    for (int i=0; i<3; i++) 
	{
        writeByte(0x3);
        wait(0.00164);  // this command takes 1.64ms, so wait for it
    }
    writeByte(0x2);     // 4-bit mode
    wait(0.000040f);    // most instructions take 40us

    writeCommand(0x28); // Function set 001 BW N F - -
    writeCommand(0x0C);
    writeCommand(0x6);  // Cursor Direction and Display Shift : 0000 01 CD S (CD 0-left, 1-right S(hift) 0-no, 1-yes
    cls();
}

void TextLCD::character(int column, int row, int c) 
{
    int a = address(column, row);
    writeCommand(a);
    writeData(c);
}

void TextLCD::cls() 
{
    writeCommand(0x01); // cls, and set cursor to 0
    wait(0.00164f);     // This command takes 1.64 ms
    locate(0, 0);
}

void TextLCD::locate(int column, int row) 
{
    m_column = column;
    m_row = row;
}

int TextLCD::_putc(int value) 
{
    if (value == '\n') 
	{
        m_column = 0;
        m_row++;
        if (m_row >= rows()) 
		{
            m_row = 0;
        }
    } 
	else 
	{
        character(m_column, m_row, value);
        m_column++;
        if (m_column >= columns()) 
		{
            m_column = 0;
            m_row++;
            if (m_row >= rows()) 
			{
                m_row = 0;
            }
        }
    }
    return value;
}

int TextLCD::_getc() 
{
    return -1;
}

void TextLCD::writeByte(int value) 
{
    m_d = value >> 4;
    wait(0.000040f); // most instructions take 40us
    m_e = 0;
    wait(0.000040f);
    m_e = 1;
    m_d = value >> 0;
    wait(0.000040f);
    m_e = 0;
    wait(0.000040f);  // most instructions take 40us
    m_e = 1;
}

void TextLCD::writeCommand(int command) {
    m_rs = 0;
    writeByte(command);
}

void TextLCD::writeData(int data) {
    m_rs = 1;
    writeByte(data);
}

int TextLCD::address(int column, int row) {
    return 0x80 + (row * 0x40) + column;
}

int TextLCD::columns() {
    return 16;
}

int TextLCD::rows() {
    return 2;
}

void TextLCD::createChar(uint8_t location, uint8_t charmap[]) 
{
  location &= 0x7; // we only have 8 locations 0-7
  writeCommand(0x40 | (location << 3)); //0x40->LCD_SET CGRAMADDR
  for (int i=0; i<8; i++) 
  {
    writeData(charmap[i]);
  }
}


