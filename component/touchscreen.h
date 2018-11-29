#ifndef TOUCHSCREEN_H
#define TOUCHSCREEN_H

#include "mbed.h"
#include "coord.h"

class Touchscreen{
	public:
		Touchscreen(PinName xp, PinName xm, PinName yp, PinName ym);
		void start();
		void stop();
		void set_callback_push(void (*fct)());
		void set_callback_pop(void (*fct)());
		void set_callback(void (*fct)());
		Coord read();
		bool get_need_update();
		void update();

	private:

		void tick();


		bool m_need_update;
		void (*m_callback_push)();
		void (*m_callback_pop)();
		void (*m_callback)();
		PinName m_xp;
		PinName m_xm;
		PinName m_yp;
		PinName m_ym;
		Ticker m_touch_ticker;
		Ticker m_read_ticker;
		bool m_touch;
		Coord m_coord;

		void touch();
};

#endif //TOUCHSCREEN_H
