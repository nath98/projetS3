#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include "mbed.h"

class Distance_sensor{
	public:
		Distance_sensor(DigitalOut* out, InterruptIn* in);
		void start_mesure();
		void set_function_mesure_ended(void (*fct)(uint16_t));

	private:
		void stop_emmition();
		void start_reading();
		void stop_reading();

		Timer m_timer;
		Timeout m_timer_mesure;
		void (*m_function_mesure_ended)(uint16_t);
		DigitalOut* m_out;
		InterruptIn* m_in;
		
};

#endif //DISTANCE_SENSOR_H
