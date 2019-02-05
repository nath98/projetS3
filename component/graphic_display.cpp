#include "graphic_display.h"

Graphic_Display::Graphic_Display(PinName mosi, PinName miso, PinName sclk, PinName cs, PinName reset, PinName dc, const char* name): SPI_TFT_ILI9341(mosi, miso, sclk, cs, reset, dc, name), Component(){
    SPI::frequency(100000000);          // 100 Mhz SPI clock
}
/*
void Graphic_Display::line(int x, int y, int taille, int coucou, int color)
{
	int i = 0;
    wr_cmd(0x2A);
    SPI::write(x >> 8);
    SPI::write(x);
    _cs = 1;
    wr_cmd(0x2B);
    SPI::write(y >> 8);
    SPI::write(y);
    _cs = 1;
    wr_cmd(0x2C);  // send pixel
	SPI::format(16,3);                            // switch to 16 bit Mode 3
	for(i = 0; i<taille; i++){
		SPI::write(color);                              // Write D0..D15
	}
  	SPI::format(8,3);
    _cs = 1;
}*/

void Graphic_Display::print(char* chaine){
	for(uint16_t i = 0; chaine[i+1]!='\0';i++){
		_putc(chaine[i]);
	}
}
