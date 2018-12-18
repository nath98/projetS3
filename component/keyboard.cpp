#include "keyboard.h"

Keyboard::Keyboard(PinName line1, PinName line2, PinName line3, PinName line4, PinName colum1, PinName colum2, PinName colum3)   /*:m_debug(USBTX, USBRX)*/{
	m_line[0] = new DigitalOut(line1);
	m_line[1] = new DigitalOut(line2);
	m_line[2] = new DigitalOut(line3);
	m_line[3] = new DigitalOut(line4);
	m_colum[0] = new InterruptIn(colum1);
	m_colum[1] = new InterruptIn(colum2);
	m_colum[2] = new InterruptIn(colum3);
	for(uint8_t i = 0; i<NUMBER_LINE; i++){
		m_line[i]->write(0);
	}
	for(uint8_t i = 0; i<NUMBER_LINE*NUMBER_COLUM; i++){
		m_button_state[i]= 0;
	}
	m_button_push = 0xFF;
	m_refresh_period = 0.01;
	m_repetition_period = 0.1;
	m_time_before_repetitions = 1;
//	m_scan = false;
	m_repetition_available = false;
	m_function_button_push= &none;	
	m_function_button_pull= &none;	
	m_function_button_push_since_limit_time = &none;
	m_function_button_push_repeated = &none;
}

Keyboard::~Keyboard(){
	delete m_line[0];
	delete m_line[1];
	delete m_line[2];
	delete m_line[3];
	delete m_colum[0];
	delete m_colum[1];
	delete m_colum[2];

}

void none(uint8_t i){}

void Keyboard::scan(){
	for(uint8_t i = 0; i<4; i++){
		m_line[i]->write(1);
		for(uint8_t j = 0; j<NUMBER_COLUM; j++){
			uint8_t v = m_colum[j]->read();
			if(v != m_button_state[(i*NUMBER_COLUM)+j]){
				m_button_state[(i*NUMBER_COLUM)+j] = v;
				if(v == 1){
					if(m_repetition_available){
						reset_repetition();
						m_wait_for_repeat.attach(callback(this, &Keyboard::start_repetition_series), m_time_before_repetitions);
					}
					m_button_push = (i*NUMBER_COLUM)+j;
					(*m_function_button_push)((i*NUMBER_COLUM)+j);
				}
				else{
					if(m_repetition_available){
						reset_repetition();
					}
					m_button_push = 0xFF;
					(*m_function_button_pull)((i*NUMBER_COLUM)+j);
				}
			}
		}
		m_line[i]->write(0);
	}
}

void Keyboard::reset_interruption(){
	stop_scanning();
	for(uint8_t i = 0; i<NUMBER_COLUM; i++){
		m_colum[i]->enable_irq();
	}
	for(uint8_t i = 0; i<NUMBER_LINE; i++){
		m_line[i]->write(1);
	}
}

void Keyboard::detect_push(){
	for(uint8_t i = 0; i<NUMBER_COLUM; i++){
		m_colum[i]->disable_irq();
	}
	for(uint8_t i = 0; i<NUMBER_LINE; i++){
		m_line[i]->write(0);
	}
	start_scanning();
}

void Keyboard::start_interrupt(){
	for(uint8_t i = 0; i<NUMBER_LINE; i++){
		m_line[i]->write(1);
	}
	for(uint8_t i = 0; i<NUMBER_COLUM; i++){
		m_colum[i]->rise(callback(this,&Keyboard::detect_push));
	}
}

void Keyboard::set_repetition_available(bool b){
	if(b){

	}
	else{
		reset_repetition();
	}
	m_repetition_available = b;
}

void Keyboard::reset_repetition(){
	m_wait_for_repeat.detach();
	m_repeat_ticker.detach();
}

void Keyboard::start_repetition_series(){
	m_repeat_ticker.attach(callback(this, (&Keyboard::member_function_button_push_repeated)),m_repetition_period);
}

void Keyboard::start_scanning(){
	m_scan = true;
	m_scan_ticker.attach(callback(this, &Keyboard::scan), m_refresh_period);
}

void Keyboard::stop_scanning(){
	m_scan = false;
	m_scan_ticker.detach();
}

void Keyboard::set_callback_push_button(void (*callback_fct)(uint8_t)){
	m_function_button_push = callback_fct;
}

void Keyboard::set_callback_pull_button(void (*callback_fct)(uint8_t)){
	m_function_button_pull = callback_fct;
}

void Keyboard::set_callback_push_button_since_limit_time(void (*callback_fct)(uint8_t)){
	m_function_button_push_since_limit_time = callback_fct;
}

void Keyboard::set_callback_push_button_repeated(void (*callback_fct)(uint8_t)){
	m_function_button_push_repeated = callback_fct;
}

void Keyboard::set_repetition_period(float p){
	m_repetition_period = p;
}

void Keyboard::set_time_before_repetition(float t){
	m_time_before_repetitions = t;
}

void Keyboard::member_function_button_push_since_limit_time(){
	(*m_function_button_push_since_limit_time)(m_button_push);
}

void Keyboard::member_function_button_push_repeated(){
	(*m_function_button_push_repeated)(m_button_push);
}

void Keyboard::set_refresh_period(float p){
	//function ticker have not to be use to wait more than some sec
	if(p>5){
		//TODO add an error
	}
	m_refresh_period = p;
}

uint8_t Keyboard::get_key(){
	return m_button_push;
}



#ifdef DEBUG
void Keyboard::print(Serial* pc){
	for(int i = 0; i<NUMBER_LINE; i++){
		
		for(int j = 0; j<NUMBER_COLUM; j++){
			pc->printf("%hd ", m_button_state[(i*4)+j]);
		}
		pc->printf("\n");
	}
	pc->printf("\n");
	pc->printf("\n");
}
#endif//DEBUG
