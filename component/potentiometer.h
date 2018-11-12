#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include "mbed.h"

class Potentiometer : public AnalogIn{
	public:
		Potentiometer(PinName p);
	private:
		
};

#endif //POTENTIOMETER_H
