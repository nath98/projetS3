#ifndef BARGRAPH_H
#define BARGRAPH_H

#include "mbed.h"
#include "component.h"

class Bargraph : public PortOut, public Component{
	public:
		Bargraph(PortName p, int mask);
	
	private:

};

#endif //BARGRAPH_H
