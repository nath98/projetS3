#include "seven_segment_display.h"

Seven_segment_display::Seven_segment_display(DigitalOut* select_pin[4], DigitalOut* value_pin[7]): m_select_pin(select_pin), m_value_pin(value_pin){
	m_time_between_2_print = 0.003;
	m_times_between_2_annim = 2;
	m_print = false;
}

Seven_segment_display::~Seven_segment_display(){

}

void Seven_segment_display::set_time_between_2_print(float time){
	m_time_between_2_print = time;
}

void Seven_segment_display::set_value(const uint8_t* value)
{
	for(int i = 0; i<4; i++){
		if(m_value_to_print[i] < 16){
			m_value_to_print[i] = value[i];
		}
		else{
			//TODO	Error, how to signal it ?
			m_value_to_print[i] = 15;
		}
	}
}

void Seven_segment_display::set_value(uint16_t value){
	for(uint8_t i = 0; i<4; i++){
		m_value_to_print[i] = value%10;
		value/=10;
	}
}

void Seven_segment_display::step_print(){
//	static uint16_t k= 0;
	static uint8_t i=0;
	for(int j = 0; j<7; j++){
		m_value_pin[j]->write(0);
	}
	m_select_pin[i]->write(1);
	i++;
	if(i>4){
		i = 0;
//		k++;
//		if(k>30){
//			k=0;
//		}
	}
	m_select_pin[i]->write(0);
	for(int j = 0; j<7; j++){
//		if(k<20)
			m_value_pin[j]->write(transcoding_tab[m_value_to_print[i]][j]);
//		else
//			m_value_pin[j]->write(!transcoding_tab[m_value_to_print[i]][j]);
	}
	if(m_print){
		m_timer.attach(callback(this, &Seven_segment_display::step_print), m_time_between_2_print);
	}
}

void Seven_segment_display::start_print(){
	m_print = true;
	step_print();
}

void Seven_segment_display::stop_print(){
	m_print = false;
}



void Seven_segment_display::right_shift(uint8_t number){
	for(uint8_t i = 1; i<4; i++){
		m_value_to_print[i-1] = m_value_to_print[i];
	}
	m_value_to_print[3] = number;
}

void Seven_segment_display::left_shift(uint8_t number){
	for(uint8_t i = 3; i>0; i--){
		m_value_to_print[i] = m_value_to_print[i-1];
	}
	m_value_to_print[0] = number;
}

void Seven_segment_display::set_number(uint8_t position, uint8_t number){
	if(position<4 && number<16){
		m_value_to_print[position] = number;
	}
	else{
		//TODO do something it’s a error !!!
	}
}

void Seven_segment_display::show_annim(){
	bool m_print = false;
	bool m_annim = true;
//	attach(callback(this, 
}


void Seven_segment_display::next_annim(){

}

void Seven_segment_display::annim_step(){
	static uint8_t number_display;
}
