#include "clock.h"

Clock::Clock(){
	m_speed = 1.0;
	m_start = false;
	m_callback = NULL;
}

void Clock::start(){
	m_start = true;
	m_ticker.attach(callback(this, &Clock::inc_time), m_speed);
}

void Clock::stop(){
	m_start = false;
	m_ticker.detach();
}

void Clock::reset(){
	if(m_start){
		m_ticker.detach();
	}
	m_time.sec = 0;
	m_time.min = 0;
	m_time.hour = 0;
	if(m_start){
		m_ticker.attach(callback(this, &Clock::inc_time), m_speed);	
	}
}

void Clock::set_callback(void (*funct)(clk_t)){
	m_callback = funct;
}

void Clock::set_speed(float speed){
	if(m_start){
		m_ticker.detach();
	}
	if(speed >0 && speed <5){
		m_speed = speed;
	}
	else{
		//TODO gestion des erreurs
	}
	if(m_start){
		m_ticker.attach(callback(this, &Clock::inc_time), m_speed);	
	}
}

void Clock::inc_time(){
	if(m_time.sec >58){
		m_time.sec = 0;
		if(m_time.min >58){
			m_time.min = 0;
			if(m_time.hour >22){
				m_time.hour = 0;
			}
			else{
				m_time.hour++;
			}
		}
		else{
			m_time.min++;
		}
	}
	else{
		m_time.sec++;
	}
	if(m_callback != NULL){
		(*m_callback)(m_time);
	 }
}
