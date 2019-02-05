#ifndef INIT_RANDOM_H
#define INIT_RANDOM_H

#include "game/game.h"
#include "component/TextLCD.h"
#include "component/random_generator.h"

class Init_Random : public Game{
	public:
		Init_Random(/*Game_Manager* game_manager,*/ Random_Generator* random_generator, TextLCD* text_lcd, PinName button);
		void start();
		void finish();

	private:
		Random_Generator* m_random_generator;
		TextLCD* m_text_lcd;
		InterruptIn m_button;
};

#endif //INIT_RANDOM_H
