#include "distance_sensor.h"

Distance_sensor::Distance_sensor(PinName out, PinName in): Component(), m_out(out), m_in(in){
	m_out = 0;
	m_in.rise(callback(this, &Distance_sensor::start_reading));
	m_in.fall(callback(this, &Distance_sensor::stop_reading));
	m_function_mesure_ended = &null_fct;
}

void Distance_sensor::start_reading(){
	m_timer.start();
}

void Distance_sensor::stop_reading(){
	m_timer.stop();
	(*m_function_mesure_ended)(m_timer.read_us());
	m_timer.reset();
}

void Distance_sensor::start_mesure(){
	m_out.write(1);
	m_timer_mesure.attach(callback(this, &Distance_sensor::stop_emmition),0.000010);
}

void Distance_sensor::stop_emmition(){
	m_out.write(0);
}

void Distance_sensor::set_function_mesure_ended(void (*fct)(uint16_t)){
	m_function_mesure_ended = fct;
}

void null_fct(uint16_t a){

}
