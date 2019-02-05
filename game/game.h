#ifndef GAME_H
#define GAME_H

#include "mbed.h"
//#include "arch/game_manager.h"

//class Game_Manager;

class Game{
	public:
		Game();//Game_Manager* game_manager);
		virtual void start()=0;
		virtual void finish()=0;
		virtual void keyboard_push(uint8_t);
		bool is_running();
		virtual void Update();

	private:
		//Game_Manager* m_game_manager;
		bool m_running;
};

#endif //GAME_H
