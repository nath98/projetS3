#include "mbed.h"

#include "arch/board.h"
#include "game/pong.h"
#include "component/coord.h"
#include "component/keyboard.h"
#include "initialisation.h"
#include "game_manager.h"
//#include "Arial24x23.h"

//Board board;

int main(){
//	board.graphic_display.cls();
//	board.graphic_display.set_font((unsigned char*) Arial24x23);
//	board.graphic_display.locate(100,100);
//	board.graphic_display.printf("coucou");
	Game_Manager gm;
//	Initialisation init(&gm, &board);
//	init.start();
//	board.keyboard.set_callback_push_button(&fct_push);
//	board.keyboard.set_callback_pull_button(&fct_pop);
//	board.keyboard.start_interrupt();
	while(1){
		gm.toDo();		
	}
}


