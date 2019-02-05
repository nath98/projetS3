#ifndef SWITCH_PORT_H
#define SWITCH_PORT_H

#include "mbed.h"
#include "component.h"


class Component;

class Switch_Port : public PortIn, public Component{
	public:
		Switch_Port(PortName p, int mask);
	
	private:

};

#endif //SWITCH_PORT
