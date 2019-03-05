#include "game_manager.h"
#include "game.h"


Game_Manager::Game_Manager(): m_board(), m_init(this, &m_board){
	start_game(&m_init);
}

void Game_Manager::set_game(Game* game){
	m_current_game.push_back(game);
}

void Game_Manager::end_game(Game* game){

}

void Game_Manager::remove_game(Game* game){
	bool c = true;
	for(uint8_t i = 0; i<m_current_game.size()&&c; i++){
		if(m_current_game[i] == game){
			m_current_game.erase(m_current_game.begin() + i);
			c = false;
		}
	}
}

void Game_Manager::toDo(){
	for(uint8_t i = 0; i<m_current_game.size(); i++){
		m_current_game[i]->toDo();
	}
}

void Game_Manager::start_game(Game* game){
	set_game(game);
	game->start();
}
