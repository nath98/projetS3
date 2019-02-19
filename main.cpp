#include "mbed.h"

#include "arch/board.h"
#include "game/pong.h"
#include "component/coord.h"
#include "component/keyboard.h"
#include "initialisation.h"
#include "game_manager.h"
//#include "Arial24x23.h"

Board board;

uint8_t global_value;
bool global_print = false;
bool global_print_pop = false;

void fct_push(uint8_t value){
	global_value = value;
	global_print = true;
}

void fct_pop(uint8_t value){
	global_value = value;
	global_print_pop = true;
}

int main(){
	global_print = true;
	board.graphic_display.cls();
	board.graphic_display.set_font((unsigned char*) Arial24x23);
	board.graphic_display.locate(100,100);
	board.graphic_display.printf("coucou");
	Game_Manager gm;
	Initialisation init(&gm, &board);
	init.start();
//	board.keyboard.set_callback_push_button(&fct_push);
//	board.keyboard.set_callback_pull_button(&fct_pop);
//	board.keyboard.start_interrupt();
	while(1){
		if(global_print){
			global_print = false;
			uint8_t value = global_value;
			board.shell.printf("push %hd\n", value);
		}
		if(global_print_pop){
			global_print_pop = false;
			uint8_t value = global_value;
			board.shell.printf("pull %hd\n", value);
		}
		gm.toDo();
		
	}
}


