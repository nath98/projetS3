#ifndef INTERFACE_H
#define INTERFACE_H

#include "game.h"
#include "arch/game_manager.h"

class Interface : public Game{
	public:
		Interface(Game_Manager* gm);
		void start();
		void stop();
		void toDo();

	private:
		

};



#endif //INTERFACE_H

