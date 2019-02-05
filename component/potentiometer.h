#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include "mbed.h"
#include "component.h"

class Component;


class Potentiometer : public AnalogIn, public Component{
	public:
		Potentiometer(PinName p);
	private:
		
};

#endif //POTENTIOMETER_H
