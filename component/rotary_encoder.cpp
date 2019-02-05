#include "rotary_encoder.h"

Rotary_Encoder::Rotary_Encoder(PinName sens1, PinName sens2): Component(), m_sens1(sens1), m_sens2(sens2){
	m_value = 0;
	m_sens1.rise(callback(this, &Rotary_Encoder::movement_detected));
	m_sens2.rise(callback(this, &Rotary_Encoder::movement_detected));
}

void Rotary_Encoder::movement_detected(){
	if(m_first_step_read){
		m_first_step_read = false;
	}
	else if(m_sens1.read() && !m_sens2.read()){
		m_value++;
		m_first_step_read = true;
	}
	else if(m_sens2.read() && !m_sens1.read()){
		m_value--;
		m_first_step_read = true;
	}

}

int32_t Rotary_Encoder::read(){
	return m_value;
}

void Rotary_Encoder::reset(){
	m_value = 0;
}

void Rotary_Encoder::set_value(int32_t value){
	m_value = value;
}

/*
void Rotary_Encoder::set_callback_sens1(void (*fct)()){
	m_callback_sens1 = fct;
}

void Rotary_Encoder::set_callback_sens2(void (*fct)()){
	m_callback_sens2 = fct;
}
*/
