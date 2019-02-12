#ifndef GAME_H
#define GAME_H

#include "mbed.h"

class Game_Manager;

class Game{
	public :
		Game(Game_Manager* gm);
		virtual void start() = 0;
		virtual void stop() = 0;
		virtual void toDo() = 0;
		virtual void get_Keyboard_push(uint8_t key);
		virtual void get_Keyboard_pull(uint8_t key);
		virtual void get_Keyboard_repeat(uint8_t key);


	private:
		Game_Manager *m_gm;

};


#endif //GAME_H
