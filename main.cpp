#include "mbed.h"
#include "component/potentiometer.h"
#include "component/seven_segment_display.h"
#include "component/keyboard.h"
#include "component/distance_sensor.h"
#include "component/clock.h"
#include "component/shell.h"
#include "component/graphic_display.h"

#include "game/pong.h"
#include "TextLCD.h"

 TextLCD lcd(PA_1, PA_2, PA_3, PA_4, PA_5, PA_6); // rs, e, d4-d7

DigitalOut* display_list_1[4] = {&DISPLAY1, &DISPLAY2, &DISPLAY3, &DISPLAY4};
DigitalOut* display_list_2[7] = {&SEGA, &SEGB, &SEGC, &SEGD, &SEGE, &SEGF, &SEGG};
Seven_segment_display display(display_list_1, display_list_2);

bool global_print_to_screen = false;
Graphic_Display gc(PA_7,PA_6, PA_5, PC_9, D8, PB_8);

int main(){
	Shell sh;
	gc.set_orientation(1);
	gc.foreground(White);    // set chars to white
	gc.cls();
	Potentiometer p1(PC_0), p2(PC_1);
	Pong p(&gc, &p1, &p2, &sh);
	int position = 30;
	const int size = 40, color = 0x00FF, xpos = 20;
	Ticker t;
	t.attach(callback(&trace_line), 0.0167);
	Clock clk;
	clk.set_callback(&ISR_timer1s);
	clk.start();
	sh.set_callback(&ISR_Callback);


	annim.push_back(etape2);
	annim.push_back(etape3);
	annim.push_back(etape4);
	annim.push_back(etape5);
	annim.push_back(etape6);
	annim.push_back(etape7);

	annim_mask.push_back(etape0);
	annim_mask.push_back(etape1b);


	uint16_t mask1[4] = {0x5555,0x5555,0x5555,0x5555};
	uint16_t mask2[4] = {0x5555,0x5555,0x5555,0x5555};
	mask.push_back(mask1);
	mask.push_back(mask1);
	
	display.set_operator_mask(mask);

//	Keyboard keyboard(keyboard_list_line, keyboard_list_colum);
//	keyboard.set_callback_push_button(&ISR_push_keyboard);
//	keyboard.start_scanning();
//	keyboard.set_callback_push_button_repeated(&ISR_push_keyboard);
//	keyboard.set_repetition_available(true);
	display.start_print();
	display.set_value(9876);
	p.start_game();
	//distanceD.set_function_mesure_ended(&get_distance);
	//distanceD.start_mesure();
	while(1){
		if(p.get_game_need_to_be_update()){
			p.update_game();
			sh.printf("%hu\n", p1.read_u16());
		}
		if(global_print_to_screen){
		/*	display.set_value((uint16_t) position);
			global_print_to_screen = false;
			gc.line(xpos, position, xpos, position+size, 0xFFFF);
			//gc.line(15,position,10, 10, 0x0000);
			if(position + size + 1 <= 320){
				position += 4;
			}
			else{
				position = 0;
			}
			gc.line(xpos, position, xpos, position+size, 0xFF00);
			//gc.line(15, position, 10,10, 0xFF00);
		*/
		}
		wait(0.001);
	}
}
