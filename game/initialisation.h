#ifndef INITIALISATION_H
#define INITIALISATION_H

#include "mbed.h"
#include "game.h"
#include "board.h"

class Game_Manager;

class Initialisation : public Game{
	public:
		Initialisation(Game_Manager* gm, Board *board);
		void start();
		void stop();
		void toDo();

	private:
		Timer m_timer;
		Board* m_board;
};

#endif //INITIALISATION_H
