#include "mbed.h"
#include "component/seven_segment_display.h"
#include "component/keyboard.h"

DigitalOut DISPLAY1(PC_8);
DigitalOut DISPLAY3(PC_6);
DigitalOut DISPLAY2(PC_5);
DigitalOut DISPLAY4(PA_12);

DigitalOut SEGB(PA_11);
DigitalOut SEGF(PB_12);
DigitalOut SEGA(PB_2);
DigitalOut SEGE(PB_1);
DigitalOut SEGG(PB_15);
DigitalOut SEGC(PB_14);
DigitalOut SEGD(PB_13);

DigitalOut KEY_LINE1(PC_10);
DigitalOut KEY_LINE2(PC_12);
DigitalOut KEY_LINE3(PD_2);
DigitalOut KEY_LINE4(PC_11);

DigitalIn KEY_COLUM1(PC_2);
DigitalIn KEY_COLUM2(PC_3);
DigitalIn KEY_COLUM3(PC_0);
DigitalIn KEY_COLUM4(PC_1);

DigitalOut* keyboard_list_line[4] = {&KEY_LINE1, &KEY_LINE2, &KEY_LINE3, &KEY_LINE4}; 
DigitalIn* keyboard_list_colum[4] = {&KEY_COLUM1, &KEY_COLUM2, &KEY_COLUM3, &KEY_COLUM4};

DigitalOut* display_list_1[4] = {&DISPLAY1, &DISPLAY2, &DISPLAY3, &DISPLAY4};
DigitalOut* display_list_2[7] = {&SEGA, &SEGB, &SEGC, &SEGD, &SEGE, &SEGF, &SEGG};
Timeout t;
Seven_segment_display display(display_list_1, display_list_2);

void test(uint8_t i){
	display.left_shift(i);
}

Serial pc(USBTX, USBRX);

int main(){
	Keyboard keyboard(keyboard_list_line, keyboard_list_colum);
	keyboard.set_callback_push_button(&test);
	keyboard.start_scruting();
	uint8_t tab[4] = {1,2,3,4};
	display.set_value(5641);
	display.start_print();
	display.set_time_between_2_print(0.0001);
	//t.attach(&test, 0.5);
	while(1){
		keyboard.print(&pc);
		wait(0.5);
	}
}
