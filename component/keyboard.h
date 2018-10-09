#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "mbed.h"

void none(uint8_t i);
class Keyboard{
	public:
		Keyboard(DigitalOut* line[4], DigitalIn* colum[4]);
		virtual ~Keyboard();
		void start_scruting();
		void scrut();
		void set_callback_push_button(void (*callback_fct)(uint8_t));
		void set_callback_pull_button(void (*callback_fct)(uint8_t));
		void print(Serial* pc);

	private:
		uint8_t m_button_state[16];//S1 : top_left, S4 : top_right, S13 : bottom_left…
		//fct pointer, to call when a button is push
		//fct pointer, to call when a button is unpush
		void (*m_fonction_button_push)(uint8_t);
		void (*m_fonction_button_pull)(uint8_t);
		DigitalOut* m_line[4];
		DigitalIn* m_colum[4];
		float m_refresh_period;
		bool m_scrut;
		Timeout m_timer;
		Serial m_debug;
};

#endif //KEYBOARD_H
