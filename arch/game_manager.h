#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "game/initialisation.h"
#include "game/pong.h"
#include <vector>
class Game;

class Game_Manager{
	public:
		Game_Manager();
		void toDo();
		//void go_to_state(
		void end_game(Game* game);

	private:
		void set_game(Game* game);
		void start_game(Game* game);
		void remove_game(Game* game);
		
		Board m_board;
		Initialisation m_init;
		//Pong m_pong;
		std::vector<Game*> m_current_game;
};


#endif //GAME_MANAGER_H
