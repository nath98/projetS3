#include "keyboard.h"

Keyboard::Keyboard(DigitalOut* line[4], DigitalIn* colum[4]): m_debug(USBTX, USBRX){
	for(uint8_t i = 0; i<4; i++){
		m_line[i]=line[i];
		m_colum[i]=colum[i];
		m_line[i]->write(0);
	}
	for(uint8_t i = 0; i<16; i++){
		m_button_state[i]= 0;
	}
	m_refresh_period = 0.01;
	m_scrut = false;
	m_fonction_button_push= &none;	
	m_fonction_button_pull= &none;	
}

Keyboard::~Keyboard(){

}

void none(uint8_t i){}

void Keyboard::start_scruting(){
	m_scrut = true;
	scrut();
}

void Keyboard::print(Serial* pc){
	for(int i = 0; i<4; i++){
		
		for(int j = 0; j<4; j++){
			pc->printf("%hd ", m_button_state[(i*4444)+j]);
		}
		pc->printf("\n");
	}
	pc->printf("\n");
	pc->printf("\n");
}

void Keyboard::scrut(){
	for(uint8_t i = 0; i<4; i++){
		m_line[i]->write(1);
		for(uint8_t j = 0; j<4; j++){
			uint8_t v = m_colum[j]->read();
			if(v != m_button_state[(i<<2)+j]){
				m_button_state[(i<<2)+j] = v;
				if(v == 1){
					(*m_fonction_button_push)((i<<2)+j);
				}
				else{
					(*m_fonction_button_pull)((i<<2)+j+1);
				}
			}
		}
		m_line[i]->write(0);
	}
//	wait(0.0001);
	m_timer.attach(callback(this, &Keyboard::scrut), m_refresh_period);
}


void Keyboard::set_callback_push_button(void (*callback_fct)(uint8_t)){
	m_fonction_button_push = callback_fct;
}

void Keyboard::set_callback_pull_button(void (*callback_fct)(uint8_t)){
	m_fonction_button_pull = callback_fct;
}
