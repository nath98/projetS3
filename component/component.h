#ifndef COMPONENT_H
#define COMPONENT_H

#include "mbed.h"

class Game;

class Component{
	public:
		Component();
		virtual void Update();
		void free();
		void set_game(Game* game);
		bool is_free();

	protected:
		Game* m_game;

};

#endif//COMPONENT_H
