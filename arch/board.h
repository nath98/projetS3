#ifndef BOARD_H
#define BOARD_H

#include "mbed.h"
#include "distance_sensor.h"
#include "graphic_display.h"
#include "keyboard.h"
#include "potentiometer.h"
#include "seven_segment_display.h"
#include "shell.h"
#include "sound.h"
#include "TextLCD.h"
#include "clock.h"
#include "touchscreen.h"

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
#define GRAPHIC_DISPAY_MOSI PB_15
#define GRAPHIC_DISPAY_MISO PB_14
#define GRAPHIC_DISPAY_CLK PB_13
#define GRAPHIC_DISPAY_CS PB_1
#define GRAPHIC_DISPAY_RESET PC_4
#define GRAPHIC_DISPAY_DC PB_2
#define KEYBOARD_L1 PA_3
#define KEYBOARD_L2 PA_2
#define KEYBOARD_L3 PA_10
#define KEYBOARD_L4 PB_3
#define KEYBOARD_C1 PB_5
#define KEYBOARD_C2 PB_4
#define KEYBOARD_C3 PB_10
#define POTENTIOMETER_RIGHT_OUT PC_2
#define POTENTIOMETER_LEFT_OUT PC_3
#define TextLCD_RS PB_7
#define TextLCD_E PC_13
#define TextLCD_D0 PC_14
#define TextLCD_D1 PC_15
#define TextLCD_D2 PH_0
#define TextLCD_D3 PH_1
#define TOUCHSCREEN_YP PC_0
#define TOUCHSCREEN_YM PC_1
#define TOUCHSCREEN_XP PB_0
#define TOUCHSCREEN_XM PA_4

class Board{
	public:
		Board();
		virtual ~Board();
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

};

#endif //BOARD_H