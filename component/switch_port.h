#ifndef SWITCH_PORT_H
#define SWITCH_PORT_H

#include "mbed.h"

class Switch_Port : public PortIn{
	public:
		Switch_Port(PortName p, int mask);
	
	private:

};

#endif //SWITCH_PORT
