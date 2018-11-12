#ifndef GRAPHIC_DISPLAY
#define GRAPHIC_DISPLAY

#include "SPI_TFT_ILI9341/SPI_TFT_ILI9341.h"
#include "mbed.h"

typedef struct{
	uint16_t x;
	uint16_t y;
}coord_t;

class Graphic_Display : public SPI_TFT_ILI9341{
	public:
		Graphic_Display(PinName mosi, PinName miso, PinName sclk, PinName cs, PinName reset, PinName dc, const char *name = "TFT");
//		void line(int x, int y, int taille, int coucou, int color);



	private:
		
};

#endif
