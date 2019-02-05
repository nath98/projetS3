/*#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H


#include "mbed.h"
//#include "game/autentification.h"
//#include "game/init_random.h"
//#include "game/pong.h"

#include <vector>
#include "board.h"

class Board;
//class Game;

class Game_Manager{
	public:
		Game_Manager();
		~Game_Manager();
		void Update();
		


	private:
		Board* m_board;
		Autentification m_autentification;
		Init_Random m_init_random;
		Pong m_pong;
		std::vector<Game*> m_game_list;

};


#endif //GAME_MANAGER_H*/
