#ifndef GAME_H
#define GAME_H

#include "mbed.h"

class Game_Manager;

class Game{
	public :
		Game();
		Game(Game_Manager* gm);
		virtual void start() = 0;
		virtual void stop() = 0;
		virtual void toDo() = 0;


	protected:
		Game_Manager *m_gm;

};


#endif //GAME_H
