#include "board.h"
/*#include "distance_sensor.h"
#include "graphic_display.h"
#include "keyboard.h"
#include "potentiometer.h"
#include "seven_segment_display.h"
#include "shell.h"
#include "TextLCD.h"
#include "clock.h"
#include "touchscreen.h"
#include "rotary_encoder.h"
#include "switch_port.h"
#include "bargraph.h"
#include "random_generator.h"
*/

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
	switch_port(SWITCH_PORT_PORT, SWITCH_PORT_MASK),
	bargraph(BARGRAPH_PORT, BARGRAPH_MASK),
	random_generator(){

	m_pointer_list.push_back(&rotary_encoder);
	m_pointer_list.push_back(&distance_sensor);
	m_pointer_list.push_back(&graphic_display);
	m_pointer_list.push_back(&keyboard);
	m_pointer_list.push_back(&text_lcd);
	m_pointer_list.push_back(&potentiometer_right);
	m_pointer_list.push_back(&potentiometer_left);
	m_pointer_list.push_back(&seven_segment_display);
	m_pointer_list.push_back(&shell);
	m_pointer_list.push_back(&clock);
	m_pointer_list.push_back(&touchscreen);
	m_pointer_list.push_back(&switch_port);
	m_pointer_list.push_back(&bargraph);
	m_pointer_list.push_back(&random_generator);
	
}

Board::~Board(){

}

void Board::Update(){
	for(uint8_t i = 0; i <m_pointer_list.size();i++){
		m_pointer_list[i]->Update();
	}
}
