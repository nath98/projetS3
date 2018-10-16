#include "seven_segment_display.h"

Seven_segment_display::Seven_segment_display(DigitalOut* select_pin[4], DigitalOut* value_pin[7]): m_select_pin(select_pin), m_value_pin(value_pin){
	m_time_between_2_print = 0.003;
	m_time_between_2_annim_image = 0.3;
	m_print = false;
	m_annim = false;
	m_annim_mask= false;
}

Seven_segment_display::~Seven_segment_display(){

}


void Seven_segment_display::set_time_between_2_print(float time){
	m_time_between_2_print = time;
}

void Seven_segment_display::set_time_between_2_annim_image(float time){
	m_time_between_2_annim_image = time;
}

void Seven_segment_display::set_annim(std::vector<uint8_t*> new_annim){
	m_annim_tab = new_annim;
}

void Seven_segment_display::set_value(const uint8_t* value){
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

void Seven_segment_display::set_value(uint32_t value){
	for(uint8_t i = 0; i<4; i++){
		m_value_to_print[i] = value%10;
		value/=10;
	}
}


void Seven_segment_display::start_print(){
	stop();
	m_annim = false;
	m_print = true;
	m_timer.attach(callback(this, &Seven_segment_display::step_print), m_time_between_2_print);
}

void Seven_segment_display::stop(){
	m_timer.detach();
	m_timer2.detach();
	m_annim_mask = false;
	m_print = false;
	m_annim = false;
}

void Seven_segment_display::start_print_with_mask(){
	stop();
	m_print = false;
	m_annim = false;
	m_annim_mask = true;
	m_timer.attach(callback(this, &Seven_segment_display::step_print), m_time_between_2_print);
	m_timer2.attach(callback(this, &Seven_segment_display::next_annim), m_time_between_2_annim_image);	
}

void Seven_segment_display::show_annim(){
	stop();
	m_print = false;
	m_annim = true;
	m_timer2.attach(callback(this, &Seven_segment_display::next_annim), m_time_between_2_annim_image);
	m_timer.attach(callback(this, &Seven_segment_display::step_print), m_time_between_2_print);	
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

void Seven_segment_display::set_operator_mask(std::vector<uint16_t*> mask){
	m_operator_annim_tab = mask;
}



void Seven_segment_display::next_annim(){
	if(m_annim_step>=m_annim_tab.size()-1){
		m_annim_step = 0;
	}
	else{
		m_annim_step++;
	}
}


/*
void Seven_segment_display::annim_step(){
	static uint8_t display_position;//number of the 7seg to use
	for(int j = 0; j<7; j++){
		m_value_pin[j]->write(0);
	}
	m_select_pin[display_position]->write(1);
	if(display_position>=3){
		display_position = 0;
	}
	else{
		display_position++;
	}
	m_select_pin[display_position]->write(0);
	for(int j = 0; j<7; j++){
	}
}*/

void Seven_segment_display::step_print(){
	static uint8_t i=0;
	for(int j = 0; j<7; j++){
		m_value_pin[j]->write(0);
	}
	m_select_pin[i]->write(1);
	i++;
	if(i>4){
		i = 0;
	}
	m_select_pin[i]->write(0);
	for(int j = 0; j<7; j++){
		if(m_annim_mask){
			uint8_t v = (uint8_t)((m_operator_annim_tab[m_annim_step][i] & (3<<(2*j)))>>(2*j));
			switch(v){
				case 0:
					m_value_pin[j]->write(transcoding_tab[m_value_to_print[i]][j]);
					break;
				case 1:
					m_value_pin[j]->write((((m_annim_tab[m_annim_step][i])&(1<<j)) != 0) & transcoding_tab[m_value_to_print[i]][j]);
					break;
				case 2:
					m_value_pin[j]->write((((m_annim_tab[m_annim_step][i])&(1<<j)) != 0) | transcoding_tab[m_value_to_print[i]][j]);
					break;
				case 3:
					m_value_pin[j]->write((((m_annim_tab[m_annim_step][i])&(1<<j)) != 0) ^ transcoding_tab[m_value_to_print[i]][j]);
					break;
			}
		}
		else if(m_annim){
			m_value_pin[j]->write((((m_annim_tab[m_annim_step][i])&(1<<j)) != 0));
		}
		else{
			m_value_pin[j]->write(transcoding_tab[m_value_to_print[i]][j]);
		}
	}
}
