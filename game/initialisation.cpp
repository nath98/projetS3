#include "initialisation.h"
#include "game_manager.h"

Initialisation* ptr_last_initialisation = NULL;

Initialisation::Initialisation(Game_Manager* gm, Board* board): Game(gm), m_board(board){
}

void Initialisation::start(){
	m_last_key_press = -1;
	ptr_last_initialisation = this;
	m_board->keyboard.set_callback_push_button(&get_keyboard_push);
//	m_board->keyboard.set_callback_pull_button(&fct_pop);
	m_board->keyboard.start_interrupt();
	m_timer.start();
	m_board->graphic_display.cls();
	m_board->graphic_display.set_font((unsigned char*) Arial24x23);
	m_board->graphic_display.locate(10,100);
	m_board->graphic_display.printf("TAPE 0 pour réinitialiser le systeme");
}

void Initialisation::stop(){
	m_gm->end_game(this);
	m_board->graphic_display.cls();
	m_board->graphic_display.locate(10,100);
	m_board->graphic_display.printf("système initialise !");
}

void Initialisation::get_keyboard(uint8_t key){
	m_last_key_press = key;	
}

void Initialisation::toDo(){
	if(m_last_key_press == 0){
		m_board->random.set_seed(m_timer.read_ms());
		stop();
	}
}

void get_keyboard_push(uint8_t key){
	if(ptr_last_initialisation != NULL){
		ptr_last_initialisation->get_keyboard(key);
	}
	else{}
}

