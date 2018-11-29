#include "touchscreen.h"

void null_fct(){}

Touchscreen::Touchscreen(PinName xp, PinName xm, PinName yp, PinName ym): m_xp(xp), m_yp(yp), m_xm(xm), m_ym(ym)
{
	AnalogIn analog_yp(m_yp);
	AnalogIn analog_xm(m_xm);
	DigitalOut digital_xp(m_xp);
	DigitalOut digital_ym(m_ym);

	digital_xp = 1;
	digital_ym = 0;
	
	m_callback = &null_fct;
	m_callback_push = &null_fct;
	m_callback_pop = &null_fct;
}

Coord Touchscreen::read(){
	//X read
	DigitalOut xp_out(m_xp);
	DigitalOut xm_out(m_xm);
	AnalogIn yp_in(m_yp);
	AnalogIn ym_in(m_ym);
	xm_out = 0;
	xp_out = 1;
	m_coord.x = ym_in.read_u16();
	xp_out = 0;

	//Y read
	DigitalOut yp_out(m_yp);
	DigitalOut ym_out(m_ym);
	AnalogIn xp_in(m_xp);
	AnalogIn xm_in(m_xm);
	ym_out = 0;
	yp_out = 1;
	m_coord.y = xp_in.read_u16();
	yp_out = 0;

	return m_coord;
}

void Touchscreen::start(){
	m_touch_ticker.attach(callback(this, &Touchscreen::tick), 0.02);
}

void Touchscreen::stop(){
	m_touch_ticker.detach();
}

void Touchscreen::set_callback_push(void (*fct)()){
	m_callback_push = fct;
}

void Touchscreen::set_callback_pop(void (*fct)()){
	m_callback_pop = fct;
}

void Touchscreen::set_callback(void (*fct)()){
	m_callback = fct;
}

void Touchscreen::tick(){
	m_need_update = true;
}

bool Touchscreen::get_need_update(){
	return m_need_update;
}

void Touchscreen::update(){
	touch();
}

void Touchscreen::touch(){
	AnalogIn analog_yp(m_yp);
	AnalogIn analog_xm(m_xm);
	DigitalOut digital_xp(m_xp);
	DigitalOut digital_ym(m_ym);

	digital_xp = 1;
	digital_ym = 0;
	

	m_need_update = false;
	bool touch = !((analog_yp.read_u16() + analog_xm.read_u16()) <  0x10FFF);
//	printf("%x\n",(analog_yp.read_u16() + analog_xm.read_u16()));
	if(touch == m_touch){
		if(m_touch){
			m_callback();
		}
	}
	else if(touch){
		m_callback_push();
	}
	else{
		m_callback_pop();
	}
	m_touch = touch;
}
