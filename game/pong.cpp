#include "pong.h"

Pong::Pong(Graphic_Display* screen, Potentiometer* p1, Potentiometer* p2, Shell* s) : m_screen(screen), m_input1(p1), m_input2(p2), m_s(s){
	m_bar_size.x = DEFAULT_BAR_SIZE_X;
	m_bar_size.y = DEFAULT_BAR_SIZE_Y;
	m_ball_speed = 10;
	m_ball_size = DEFAULT_BALL_SIZE;
	m_screen_size.x = m_screen->width();
	m_screen_size.y = m_screen->height();
	m_screen->fillrect(40, m_bar_position[0].x, 50, m_bar_position[0].x + m_bar_size.y, 0xFFFF);
}

void Pong::start_game(){
	m_ticker.attach(callback(this, &Pong::game_need_to_be_update), 0.1);
}

void Pong::stop_game(){
	m_ticker.detach();
}

bool Pong::get_game_need_to_be_update(){
	return m_game_need_to_be_update;
}

void Pong::game_need_to_be_update(){
	m_game_need_to_be_update = true;
}

void Pong::update_game(){
	static coord_t new_bar_position[2];
	m_game_need_to_be_update = false;
	//move the bar
	new_bar_position[0].x = (uint16_t)((((uint32_t)m_input1->read_u16())*(m_screen_size.y-m_bar_size.y))/(0xFFFF));
	//check colision

	//calculate new ball_position

	//display all 
	m_screen->fillrect(5, m_bar_position[0].x, 10, m_bar_position[0].x + m_bar_size.y, 0x0000);
	m_bar_position[0].x = new_bar_position[0].x;
	m_screen->fillrect(5, m_bar_position[0].x, 10, m_bar_position[0].x + m_bar_size.y, 0xFFFF);
}
