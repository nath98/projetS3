#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include "mbed.h"
#include "component.h"
#include "game.h"

class Random_Generator : public Component{
	public:
		Random_Generator();
		uint16_t rand_u16(uint16_t min = 0, uint16_t max = 0xFFFF);
		void set_game(Game*);
		void init();


	private:
		Timer m_timer;
};

#endif //RANDOM_GENERATOR_H
