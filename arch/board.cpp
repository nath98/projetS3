#include "board.h"

Board::Board(): 
	clock(),
	distance_sensor(DISTANCE_SENSOR_OUT,
		       	DISTANCE_SENSOR_IN),
	graphic_display(GRAPHIC_DISPAY_MOSI,
		       	GRAPHIC_DISPAY_MISO,
		       	GRAPHIC_DISPAY_CLK,
		       	GRAPHIC_DISPAY_CS, 
			GRAPHIC_DISPAY_RESET, 
			GRAPHIC_DISPAY_DC),
       	keyboard(KEYBOARD_L1,
		 KEYBOARD_L2,
		 KEYBOARD_L3,
		 KEYBOARD_L4, 
		 KEYBOARD_C1,
	 	 KEYBOARD_C2, 
 		 KEYBOARD_C3),
       	potentiometer_right(POTENTIOMETER_RIGHT_OUT),
       	potentiometer_left(POTENTIOMETER_LEFT_OUT),
       	seven_segment_display(SEVEN_SEGMENT_DISPLAY_SELECT1,
			      SEVEN_SEGMENT_DISPLAY_SELECT2,
			      SEVEN_SEGMENT_DISPLAY_SELECT3,
			      SEVEN_SEGMENT_DISPLAY_SELECT4,
			      SEVEN_SEGMENT_DISPLAY_SEG1,
			      SEVEN_SEGMENT_DISPLAY_SEG2,
		      	      SEVEN_SEGMENT_DISPLAY_SEG3,
		      	      SEVEN_SEGMENT_DISPLAY_SEG4,
		      	      SEVEN_SEGMENT_DISPLAY_SEG5,
		      	      SEVEN_SEGMENT_DISPLAY_SEG6,
		      	      SEVEN_SEGMENT_DISPLAY_SEG7),
       	shell(),
       	text_lcd(TextLCD_RS,
		 TextLCD_E,
		 TextLCD_D0,
		 TextLCD_D1,
		 TextLCD_D2, 
		 TextLCD_D3),
	touchscreen(TOUCHSCREEN_XP, 
		    TOUCHSCREEN_XM, 
		    TOUCHSCREEN_YP, 
		    TOUCHSCREEN_YM),
	rotary_encoder(ROTARY_ENCODE_SENS1, ROTARY_ENCODE_SENS2),
	switch_port(SWITCH_PORT_PORT, SWITCH_PORT_MASK){
	
}

Board::~Board(){

}


