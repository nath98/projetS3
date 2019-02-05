#include "mbed.h"

#include "arch/board.h"
#include "game/pong.h"
#include "game/autentification.h"
#include "game/init_random.h"
#include "component/coord.h"
#include "component/keyboard.h"
#include "helpers/digital.h"
#include "Arial12x12.h"

Board board;

using namespace Digital;

int main(){
	Game_Manager gm;
	board.shell.delay_print("coucou");
	Init_Random init(&gm,&board.random_generator, &board.text_lcd, PC_5);
	Autentification aut(&gm,&board.random_generator, &board.text_lcd, &board.shell, &board.keyboard);
	init.start();
	for(uint32_t i = 0; i<5; i++){
		wait(3);
	}
	aut.start();
	
	board.graphic_display.claim(stdout);
	board.graphic_display.background(Black);
	board.graphic_display.foreground(White);
	board.graphic_display.cls();
	board.graphic_display.set_font((unsigned char*) Arial12x12);
	board.graphic_display.locate(10,10);
	printf("coucou\nplein beaucoup de blabla\n\n\n du blabla plus loing et en plus c’est vraiment très long !!!!");
	//Pong p(&board.graphic_display, &board.potentiometer_right, &board.potentiometer_left, &board.shell);
	//p.start_game();
	while(1){
		board.Update();
		aut.Update();
		//p.update_game();
	}
}


