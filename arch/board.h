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

#define DISTANCE_SENSOR_IN PC_11
#define DISTANCE_SENSOR_OUT PD_2
#define GRAPHIC_DISPAY_MISO PB_4
#define GRAPHIC_DISPAY_MOSI PB_5
#define GRAPHIC_DISPAY_CLK PB_3
#define GRAPHIC_DISPAY_CS PA_10
#define GRAPHIC_DISPAY_RESET PA_2
#define GRAPHIC_DISPAY_DC PA_3
#define KEYBOARD_L1 PA_3
#define KEYBOARD_L2 PA_2
#define KEYBOARD_L3 PA_10
#define KEYBOARD_L4 PB_3
#define KEYBOARD_C1 PB_5
#define KEYBOARD_C2 PB_4
#define KEYBOARD_C3 PB_10
#define POTENTIOMETER_RIGHT_OUT PC_2
#define POTENTIOMETER_LEFT_OUT PC_3
#define TextLCD_RS PA_0
#define TextLCD_E PA_1
#define TextLCD_D0 PA_4
#define TextLCD_D1 PB_0
#define TextLCD_D2 PC_1
#define TextLCD_D3 PC_0
#define SEVEN_SEGMENT_DISPLAY_SEG1 PC_8
#define SEVEN_SEGMENT_DISPLAY_SEG2 PC_6
#define SEVEN_SEGMENT_DISPLAY_SEG3 PC_5
#define SEVEN_SEGMENT_DISPLAY_SEG4 PA_12
#define SEVEN_SEGMENT_DISPLAY_SEG5 PA_11
#define SEVEN_SEGMENT_DISPLAY_SEG6 PB_12
#define SEVEN_SEGMENT_DISPLAY_SEG7 PB_2
#define SEVEN_SEGMENT_DISPLAY_SELECT1 PB_1
#define SEVEN_SEGMENT_DISPLAY_SELECT2 PB_15
#define SEVEN_SEGMENT_DISPLAY_SELECT3 PB_14
#define SEVEN_SEGMENT_DISPLAY_SELECT4 PB_13

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

};

#endif //BOARD_H
