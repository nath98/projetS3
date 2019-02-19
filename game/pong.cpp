#include "pong.h"
//#include "game_manager.h"

Pong::Pong(/*Game_Manager* gm,*/ Graphic_Display* screen, Potentiometer* p1, Potentiometer* p2, Shell* s) : Game(/*gm*/), m_screen(screen), m_input1(p1), m_input2(p2), m_s(s){
	m_screen->background(0x0000);
	m_screen->set_orientation(1);
	m_screen->cls();
	m_bar_size = DEFAULT_BAR_SIZE;
	m_ball_speed.x = -5;
	m_ball_speed.y = 0;
	m_ball_diameter = DEFAULT_BALL_DIAMETER;
	m_screen_size.x = m_screen->width();
	m_screen_size.y = m_screen->height();
	m_ball_position.x = m_screen_size.x/2;
	m_ball_position.y = m_screen_size.y/2;
	m_s->printf("coucou\n");
}

void Pong::start(){
	m_ticker.attach(callback(this, &Pong::game_need_to_be_update), 0.02);
}

void Pong::stop(){
	m_ticker.detach();
}

bool Pong::get_game_need_to_be_update(){
	return m_game_need_to_be_update;
}

void Pong::game_need_to_be_update(){
	m_game_need_to_be_update = true;
}

void Pong::toDo(){
	//clear to allow next update
	m_game_need_to_be_update = false;

	//calcul futur move
	//move the bar
	uint8_t new_bar_position[2];
	new_bar_position[0] = (uint16_t)((((uint32_t)m_input1->read_u16())*(m_screen_size.y-1-m_bar_size))/(0xFFFF));
	new_bar_position[1] = (uint16_t)((((uint32_t)m_input2->read_u16())*(m_screen_size.y-1-m_bar_size))/(0xFFFF));

	//move ball
	coord_t new_ball_position = {m_ball_position.x + m_ball_speed.x, m_ball_position.y - m_ball_speed.y};
	
	//check colision
	//with top bar
	if(new_ball_position.y-m_ball_diameter <= 0){
		m_ball_speed.y *= -1;
		m_ball_position.y *= -1;
	}
	//with bottom bar
	else if(new_ball_position.y+m_ball_diameter >= m_screen_size.y-1){
		m_ball_speed.y *= -1;
		m_ball_position.y = ((m_screen_size.y-1) << 2) - m_ball_position.y;//(y-320)*-1 + 320 == (2*320)-y
	}
	//with left bar
	if(new_ball_position.x-m_ball_diameter < DISTANCE_FROM_SCREEN_LIMIT+BAR_WIDTH){
		float coef = (m_ball_position.x-(DISTANCE_FROM_SCREEN_LIMIT+BAR_WIDTH))/m_ball_speed.x;
		float real_y_position = m_ball_position.y + coef*m_ball_speed.y;
		if(real_y_position + m_ball_diameter < m_bar_position[0] || real_y_position - m_ball_diameter - m_bar_size > m_bar_position[0]){ 
			//the ball is out of bar range
			//add one point to player 2 (id 1)
			new_ball_position.x = m_screen_size.x/2;
			new_ball_position.y = m_screen_size.y/2;
			m_ball_speed.y = 0;
			m_ball_speed.x = -2;
		}
		else{
			float deviation_coef = (((m_bar_position[0]-real_y_position)*2.0)/m_bar_size)+1;
			m_ball_speed.y = deviation_coef*-2.0*m_ball_speed.x;
			m_ball_speed.x *= -1;
			new_ball_position.x += 2*(DISTANCE_FROM_SCREEN_LIMIT+BAR_WIDTH-new_ball_position.x) ;
		}

	}
	else if (new_ball_position.x+m_ball_diameter>m_screen_size.x - DISTANCE_FROM_SCREEN_LIMIT -BAR_WIDTH){
		float coef = (m_ball_position.x-m_screen_size.x - (DISTANCE_FROM_SCREEN_LIMIT+BAR_WIDTH))/m_ball_speed.x;
		float real_y_position = m_ball_position.y + coef*m_ball_speed.y;
		if(real_y_position + m_ball_diameter < m_bar_position[1] || real_y_position - m_ball_diameter - m_bar_size > m_bar_position[1]){ 
			new_ball_position.x = m_screen_size.x/2;
			new_ball_position.y = m_screen_size.y/2;
			m_ball_speed.y = 0;
			m_ball_speed.x = 2;
		}
		else{
			float deviation_coef = (((m_bar_position[1]-real_y_position)*2.0)/m_bar_size)+1;
			m_ball_speed.y = deviation_coef*2.0*m_ball_speed.x;
			m_ball_speed.x *= -1;
			m_ball_position.x -= 2*(DISTANCE_FROM_SCREEN_LIMIT+BAR_WIDTH-m_ball_position.x) ;
		}
	}
	//with right bar

	//calculate new ball_position

	//display all 
	//player 1
	m_bar_position[0] = new_bar_position[0];
	m_screen->fillrect(DISTANCE_FROM_SCREEN_LIMIT, 0, DISTANCE_FROM_SCREEN_LIMIT+BAR_WIDTH, m_bar_position[0], 0x0000);
	m_screen->fillrect(DISTANCE_FROM_SCREEN_LIMIT, m_bar_position[0]+m_bar_size , BAR_WIDTH+DISTANCE_FROM_SCREEN_LIMIT, m_screen_size.y-1, 0x0000);
	m_screen->fillrect(DISTANCE_FROM_SCREEN_LIMIT, m_bar_position[0], BAR_WIDTH+DISTANCE_FROM_SCREEN_LIMIT, m_bar_position[0] + m_bar_size, 0xFF00);

	//player 2
	m_bar_position[1] = new_bar_position[1];
	m_screen->fillrect(m_screen_size.x - DISTANCE_FROM_SCREEN_LIMIT - BAR_WIDTH, 0, m_screen_size.x - DISTANCE_FROM_SCREEN_LIMIT, m_bar_position[1], 0x0000);
	m_screen->fillrect(m_screen_size.x - DISTANCE_FROM_SCREEN_LIMIT - BAR_WIDTH, m_bar_position[1]+m_bar_size , m_screen_size.x - DISTANCE_FROM_SCREEN_LIMIT, m_screen_size.y-1, 0x0000);
	m_screen->fillrect(320 - DISTANCE_FROM_SCREEN_LIMIT - BAR_WIDTH, m_bar_position[1], 320 - DISTANCE_FROM_SCREEN_LIMIT, m_bar_position[1] + m_bar_size, 0xFF00);

	//ball
	m_screen->fillrect(m_ball_position.x-m_ball_diameter, m_ball_position.y - m_ball_diameter, m_ball_position.x + m_ball_diameter, m_ball_position.y + m_ball_diameter, 0x0000);
	m_ball_position.x = new_ball_position.x;
	m_ball_position.y = new_ball_position.y;
	m_screen->fillrect(m_ball_position.x-m_ball_diameter, m_ball_position.y - m_ball_diameter, m_ball_position.x + m_ball_diameter, m_ball_position.y + m_ball_diameter, 0xFFFF);
}
