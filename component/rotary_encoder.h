#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include "mbed.h"

class Rotary_Encoder{
	public:
		Rotary_Encoder(PinName sens1, PinName sens2);
		void Int();
		int32_t read();
		void reset();
		void set_value(int32_t value);


	private:
		int32_t m_value;
		bool m_first_step_read;
		void movement_detected();
		InterruptIn m_sens1;
		InterruptIn m_sens2;
};


#endif //ROTARY_ENCODER_H
