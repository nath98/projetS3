#ifndef PONG_H
#define PONG_H

#include "mbed.h"
#include "../component/graphic_display.h"
#include "../component/potentiometer.h"
#include "../component/shell.h"

#define DEFAULT_BALL_SIZE 9
#define DEFAULT_BAR_SIZE_X 4
#define DEFAULT_BAR_SIZE_Y 20

class Pong{
	public:
		Pong(Graphic_Display* screen, Potentiometer* p1, Potentiometer* p2, Shell* s);
		void start_game();
		void stop_game();
		bool get_game_need_to_be_update();
		void update_game();
	
	private:
		bool m_game_need_to_be_update;
		void game_need_to_be_update();
		
		Shell* m_s;

		Ticker m_ticker;
		
		Potentiometer* m_input1;
		Potentiometer* m_input2;
		Graphic_Display* m_screen;
		uint16_t m_ball_position[2];
		coord_t m_bar_position[2];
		coord_t m_screen_size;
		uint8_t m_ball_size;
		coord_t m_bar_size;
		uint8_t m_ball_speed;
		
};

#endif //PONG_H
