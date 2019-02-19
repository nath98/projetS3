#ifndef COMPONENT_H
#define COMPONENT_H

#include "mbed.h"
#include "game.h"

class Component{
	public :
		Component();
		void set_game(Game* game);

	private:
		Game* m_game;
};


#endif //COMPONENT_H
