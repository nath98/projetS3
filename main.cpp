#include "mbed.h"

#include "arch/board.h"
#include "game/pong.h"
#include "component/coord.h"

Board board;

bool global_print_pos;
Coord global_pos;

void touchscreen_push(){
	global_print_pos = true;
	global_pos = board.touchscreen.read();
}

int main(){
	Pong pong(&(board.graphic_display), &(board.potentiometer_right), &(board.potentiometer_left), &(board.shell));
	pong.start_game();
	board.touchscreen.set_callback_push(touchscreen_push);
	board.touchscreen.start();
	while(1){
		if(global_print_pos){
			global_print_pos = false;
			board.shell.printf("touch : %hu\t%hu\n", global_pos.x/256, global_pos.y/256);
		}
		if(board.touchscreen.get_need_update()){
			board.touchscreen.update();
		}
		if(pong.get_game_need_to_be_update()){
			pong.update_game();
		}
		wait(0.0001);
	}
}


