#include "mbed.h"
#include "component/seven_segment_display.h"
#include "component/keyboard.h"
#include "component/distance_sensor.h"
#include "component/clock.h"

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


InterruptIn DISTANCE_IN(PA_13);
DigitalOut DISTANCE_OUT(PA_14);

DigitalOut* keyboard_list_line[4] = {&KEY_LINE1, &KEY_LINE2, &KEY_LINE3, &KEY_LINE4}; 
DigitalIn* keyboard_list_colum[4] = {&KEY_COLUM1, &KEY_COLUM2, &KEY_COLUM3, &KEY_COLUM4};

DigitalOut* display_list_1[4] = {&DISPLAY1, &DISPLAY2, &DISPLAY3, &DISPLAY4};
DigitalOut* display_list_2[7] = {&SEGA, &SEGB, &SEGC, &SEGD, &SEGE, &SEGF, &SEGG};
Timeout t;
Seven_segment_display display(display_list_1, display_list_2);

uint8_t etape0[4] = {0xFF,0xFF,0xFF,0xFF};
uint8_t etape1b[4] = {0,0,0,0};
uint8_t etape1[4] = {0,0,0,0};
uint8_t etape2[4] = {1,1,1,1};
uint8_t etape3[4] = {2,2,2,2};
uint8_t etape4[4] = {4,4,4,4};
uint8_t etape5[4] = {8,8,8,8};
uint8_t etape6[4] = {16,16,16,16};
uint8_t etape7[4] = {32,32,32,32};
uint8_t etape8[4] = {64,64,64,64};



Distance_sensor distanceD(&DISTANCE_OUT, &DISTANCE_IN);

bool display_time = false;
std::vector<uint8_t*> annim;
std::vector<uint8_t*> annim_mask;
std::vector<uint16_t*> mask;

void ISR_push_keyboard(uint8_t value){
	static uint8_t tab[4];
	static bool init = false;
	static uint8_t cursor = 0;
	if(!init){
		tab[0] = 0;
		tab[1] = 0;
		tab[2] = 0;
		tab[3] = 0;
		init = true;
	}
	switch(value){
		case 0x1:
			if(tab[cursor] >= 0xF){
				tab[cursor] = 0;
			}
			else{
				tab[cursor]++;
			}
			break;
		case 0x04:
			if(cursor >= 3){
				cursor = 0;
			}
			else{
				cursor++;
			}
			for(uint8_t i = 0; i<4; i++){
				annim_mask[1][i] = 0xFF;
			}
			annim_mask[1][cursor] = 0x00;
			
			break;
		case 0x06:
			if(cursor <=0){
				cursor = 3;
			}
			else{
				cursor--;
			}
			for(uint8_t i = 0; i<4; i++){
				annim_mask[1][i] = 0xFF;
			}
			annim_mask[1][cursor] = 0x00;
			break;
		case 0x09:
			if(tab[cursor] <= 0){
				tab[cursor] = 0xF;
			}
			else{
				tab[cursor]--;
			}
			break;
		case 0xF:
			distanceD.start_mesure();
			//validate
			break;
		case 0xC:
			display.start_print();
			display_time = true;
			break;
		case 0xD:
			display.set_annim(annim_mask);
			display.start_print_with_mask();
			display.set_value(1234);
			display_time = false;
			break;
		case 0xE:
			display.show_annim();
		default:
			break;
	}
	display.set_value(tab);
}


void ISR_timer1s(clk_t time){
/*	static uint8_t sec = 0;
	static uint8_t min = 0;
	if(sec>=59){
		sec = 0;
		if(min>=59){
			min = 0;
		}
		else{
			min++;
		}
	}
	else{
		sec++;
	}
	uint8_t tab[4];
	tab[0]= sec%10;
	tab[1] = sec/10;
	tab[2] = min%10;
	tab[3] = min/10;*/
	if(display_time){
		display.set_value(time.min*100+time.sec);
	}
}

void get_distance(uint16_t distance){
	display.set_value(distance/58);
}

int main(){
	Clock clk;
	clk.set_callback(&ISR_timer1s);
	clk.start();
	Serial pc(USBTX, USBRX);
	pc.baud(9600);
	pc.printf("bite !!!");
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

	Keyboard keyboard(keyboard_list_line, keyboard_list_colum);
	keyboard.set_callback_push_button(&ISR_push_keyboard);
	keyboard.start_scanning();
	keyboard.set_callback_push_button_repeated(&ISR_push_keyboard);
	keyboard.set_repetition_available(true);
	display.start_print();
	distanceD.set_function_mesure_ended(&get_distance);
	distanceD.start_mesure();
	uint8_t b = 0;
	while(1){
	}
}
