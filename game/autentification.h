#ifndef AUTENTIFICATION_H
#define AUTENTIFICATION_H

#include <queue>
#include "board.h"
#include "mbed.h"
#include "game.h"
#include "random.h"
#include "TextLCD.h"
#include "shell.h"
#include "keyboard.h"
#include "component.h"
#include "helpers/digital.h"

using namespace Digital;

#define NUMBER_OF_CARACT_IN_CODE 4

class Autentification : public Game{
	public:
		Autentification(Game_Manager* game_manager, Board* board);
		void start();
		void stop();
		virtual void keyboard_push(uint8_t);
		virtual void toDo();

	private:
		bool check_code();
		void init_graphic();


		Random* m_random_generator;
		TextLCD* m_text_lcd;
		Shell* m_shell;
		Keyboard* m_keyboard;

		uint8_t m_secret_number[NUMBER_OF_CARACT_IN_CODE];
		uint16_t m_secret_number_in_dec;
		uint8_t m_try[NUMBER_OF_CARACT_IN_CODE];
		uint8_t m_try_id;
		uint8_t m_number_of_try;
		std::queue<uint8_t> m_number_list;

		Board* m_board;


};

void get_keyboard_push_aut(uint8_t key);

#endif //AUTENTIFICATION_H
