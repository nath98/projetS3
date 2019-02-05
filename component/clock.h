#ifndef CLOCK_H
#define CLOCK_H

#include "mbed.h"

typedef struct {
	uint8_t hour = 0;
	uint8_t min = 0;
	uint8_t sec = 0;
} clk_t;

class Clock{
	public:
		Clock();
		void start();
		void stop();
		void reset();
		clk_t get_time();
		void set_callback(void (*funct)(clk_t));
		void set_speed(float speed);//if speed = 1 => normal speed, speed = 0.5 => 0.5 x speep (1 timer minutes = 2 real minutes), speed need to be < 5.0 /!\ the ticker is not restart ! so to apply modification you have to restart (by calling start())
	private:
		void inc_time();
		
		void (*m_callback)(clk_t);

		bool m_start;
		Ticker m_ticker;
		float m_speed;
		clk_t m_time;
};

#endif//CLOCK_H
