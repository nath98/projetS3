#include "seven_segment_display.h"

Seven_segment_display::Seven_segment_display(PinName select1, PinName select2, PinName select3, PinName select4, PinName seg1, PinName seg2, PinName seg3, PinName seg4, PinName seg5, PinName seg6, PinName seg7 ): Component(){
	m_select_pin[0] = new DigitalOut(select1);
	m_select_pin[1] = new DigitalOut(select2);
	m_select_pin[2] = new DigitalOut(select3);
	m_select_pin[3] = new DigitalOut(select4);
	m_value_pin[0] = new DigitalOut(seg1);
	m_value_pin[1] = new DigitalOut(seg2);
	m_value_pin[2] = new DigitalOut(seg3);
	m_value_pin[3] = new DigitalOut(seg4);
	m_value_pin[4] = new DigitalOut(seg5);
	m_value_pin[5] = new DigitalOut(seg6);
	m_value_pin[6] = new DigitalOut(seg7);
	m_time_between_2_print = 0.003;
	m_time_between_2_annim_image = 0.3;
	m_print = false;
	m_annim = false;
	m_annim_mask= false;
	m_common_anode = 1;
}

Seven_segment_display::~Seven_segment_display(){
	delete m_select_pin[0];
	delete m_select_pin[1];
	delete m_select_pin[2];
	delete m_select_pin[3];
	delete m_value_pin[0];
	delete m_value_pin[1];
	delete m_value_pin[2];
	delete m_value_pin[3];
	delete m_value_pin[4];
	delete m_value_pin[5];
	delete m_value_pin[6];
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
		m_value_pin[j]->write(m_common_anode);
	}
	m_select_pin[i]->write(!m_common_anode);
	i++;
	if(i>4){
		i = 0;
	}
	m_select_pin[i]->write(m_common_anode);
	for(int j = 0; j<7; j++){
		if(m_annim_mask){
			uint8_t v = (uint8_t)((m_operator_annim_tab[m_annim_step][i] & (3<<(2*j)))>>(2*j));
			switch(v){
				case 0:
					m_value_pin[j]->write(transcoding_tab[m_value_to_print[i]][j]^m_common_anode);
					break;
				case 1:
					m_value_pin[j]->write(((((m_annim_tab[m_annim_step][i])&(1<<j)) != 0) & transcoding_tab[m_value_to_print[i]][j])^m_common_anode);
					break;
				case 2:
					m_value_pin[j]->write(((((m_annim_tab[m_annim_step][i])&(1<<j)) != 0) | transcoding_tab[m_value_to_print[i]][j])^m_common_anode);
					break;
				case 3:
					m_value_pin[j]->write(((((m_annim_tab[m_annim_step][i])&(1<<j)) != 0) ^ transcoding_tab[m_value_to_print[i]][j])^m_common_anode);
					break;
			}
		}
		else if(m_annim){
			m_value_pin[j]->write(((((m_annim_tab[m_annim_step][i])&(1<<j)) != 0))^m_common_anode);

		}
		else{
			m_value_pin[j]->write((transcoding_tab[m_value_to_print[i]][j])^m_common_anode);
		}
	}
}
