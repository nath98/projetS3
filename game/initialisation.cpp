#include "initialisation.h"
#include "game_manager.h"

Initialisation::Initialisation(Game_Manager* gm, Board* board): Game(gm), m_board(board){

}

void Initialisation::start(){
	m_timer.start();
}

void Initialisation::stop(){

}

void Initialisation::toDo(){
	m_board->random.set_seed(m_timer.read_ms());
}
