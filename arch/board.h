#ifndef BOARD_H
#define BOARD_H

#include "mbed.h"
#include "distance_sensor.h"
#include "graphic_display.h"
#include "component/keyboard.h"
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

/*class Distance_Sensor;
class Graphic_Display;
class Keyboard;
class Potentiometer;
class Seven_Segment_Display;
class Shell;
class Clock;
class TextLCD;
class Touchscreen;
class Rotary_Encoder;
class Switch_Port;
class Bargraph;
class Random_Generator;*/
#include <vector>

#define SWITCH_PORT_MASK 0x00000FF
#define SWITCH_PORT_PORT PortC

#define BARGRAPH_MASK 0x00000FF
#define BARGRAPH_PORT PortC

#define SEVEN_SEGMENT_DISPLAY_SEG1 D0
#define SEVEN_SEGMENT_DISPLAY_SEG2 D1
#define SEVEN_SEGMENT_DISPLAY_SEG3 D2
#define SEVEN_SEGMENT_DISPLAY_SEG4 D3
#define SEVEN_SEGMENT_DISPLAY_SEG5 D4
#define SEVEN_SEGMENT_DISPLAY_SEG6 D5
#define SEVEN_SEGMENT_DISPLAY_SEG7 D6
#define SEVEN_SEGMENT_DISPLAY_SELECT1 D7
#define SEVEN_SEGMENT_DISPLAY_SELECT2 D8
#define SEVEN_SEGMENT_DISPLAY_SELECT3 D9
#define SEVEN_SEGMENT_DISPLAY_SELECT4 D10
#define DISTANCE_SENSOR_IN PC_11
#define DISTANCE_SENSOR_OUT PD_2

#define GRAPHIC_DISPAY_RESET PC_4
#define GRAPHIC_DISPAY_CLK PB_13
#define GRAPHIC_DISPAY_MISO PB_14
#define GRAPHIC_DISPAY_MOSI PB_15
#define GRAPHIC_DISPAY_CS PB_1
#define GRAPHIC_DISPAY_DC PB_2

#define KEYBOARD_L1 PA_5
#define KEYBOARD_L2 PA_6
#define KEYBOARD_L3 PA_7
#define KEYBOARD_L4 PC_7
#define KEYBOARD_C1 PB_9
#define KEYBOARD_C2 PB_8
#define KEYBOARD_C3 PC_9

#define POTENTIOMETER_RIGHT_OUT A1 
#define POTENTIOMETER_LEFT_OUT A2

#define TextLCD_RS PB_7
#define TextLCD_E PC_13
#define TextLCD_D0 PC_14
#define TextLCD_D1 PC_15
#define TextLCD_D2 PH_0
#define TextLCD_D3 PH_1

#define TOUCHSCREEN_YP PC_2
#define TOUCHSCREEN_YM PC_3
#define TOUCHSCREEN_XP PB_0
#define TOUCHSCREEN_XM PA_4

#define ROTARY_ENCODE_SENS1 PC_10
#define ROTARY_ENCODE_SENS2 PC_12

#define MATRIX_DR1
#define MATRIX_DG1
#define MATRIX_DB1
#define MATRIX_DR2
#define MATRIX_DG2
#define MATRIX_DB2
#define MATRIX_A
#define MATRIX_B
#define MATRIX_C
#define MATRIX_D
#define MATRIX_CLK
#define MATRIX_LAT
#define MATRIX_OE

#define RANDOM_GENERATOR PC_5

class Board{
	public:
		Board();
		void Update();
		virtual ~Board();
		Rotary_Encoder rotary_encoder;
		Distance_sensor distance_sensor;
		Graphic_Display graphic_display;
		Keyboard keyboard;
		TextLCD text_lcd;
		Potentiometer potentiometer_right;
		Potentiometer potentiometer_left;
		Seven_segment_display seven_segment_display;
		Shell shell;
		Clock clock;
		Touchscreen touchscreen;
		Switch_Port switch_port;
		Bargraph bargraph;
		Random_Generator random_generator;
		
	private:
		std::vector<Component*> m_pointer_list;
};

#endif //BOARD_H
