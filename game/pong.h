#ifndef PONG_H
#define PONG_H

#include "mbed.h"
#include "../component/graphic_display.h"
#include "../component/potentiometer.h"
#include "../component/shell.h"
#include "game.h"

class Game_Manager;

#define DEFAULT_BALL_DIAMETER 3
#define DEFAULT_BAR_SIZE 50

#define DISTANCE_FROM_SCREEN_LIMIT 6
#define BAR_WIDTH 4

class Pong : public Game{
	public:
		Pong(Game_Manager* gm, Graphic_Display* screen, Potentiometer* p1, Potentiometer* p2, Shell* s);
		void start();
		void stop();
		bool get_game_need_to_be_update();
		void toDo();
	
	private:
		bool m_game_need_to_be_update;
		void game_need_to_be_update();
		
		Shell* m_s;

		Ticker m_ticker;
		
		Potentiometer* m_input1;
		Potentiometer* m_input2;

		Graphic_Display* m_screen;
		coord_t m_screen_size;


		coord_t m_ball_position;// /!\ the reference is the middle of the ball (extremity = position + diameter)
		coord_t m_ball_speed;
		uint8_t m_ball_diameter;


		uint16_t m_bar_position[2];// /!\ the reference is the top of bar (bottom of the bar is position + size)
		uint16_t m_bar_size;
		
};

#endif //PONG_H
