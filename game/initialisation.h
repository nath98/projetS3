#ifndef INITIALISATION_H
#define INITIALISATION_H

#include "mbed.h"
#include "game.h"
#include "board.h"
#include "random.h"

class Game_Manager;

class Initialisation  : public Game{
	public:
		Initialisation(Game_Manager* gm, Board *board);
		void start();
		void stop();
		void toDo();
		void get_keyboard(uint8_t key);

	private:
		Timer m_timer;
		Board* m_board;
		uint8_t m_last_key_press;
};   


void get_keyboard_push(uint8_t key);

#endif //INITIALISATION_H
