/*#include "game_manager.h"
#include "game.h"
#include "pong.h"
#include "board.h"

Game_Manager::Game_Manager(){
	m_board = new Board();
	//Autentification(this, &board->game_manager, &board->random_generator, &board->text_lcd, &board->shell, &board->keyboard);
	//Init_Random(this, &board->random_generator, &board->text_lcd, PC_5);
	//Pong(this, &board->graphic_display(), &board->potentiometer_right, &board->potentiometer_left);
	
}

Game_Manager::~Game_Manager(){
}


void Game_Manager::Update(){
	for(uint8_t i = 0; i <m_game_list.size(); i++){
		if(m_game_list[i]->is_running()){
			m_game_list[i]->Update();
		}
	}
}*/
