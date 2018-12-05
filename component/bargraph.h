#ifndef BARGRAPH_H
#define BARGRAPH_H

#include "mbed.h"

class Bargraph : public PortOut{
	public:
		Bargraph(PortName p, int mask);
	
	private:

};

#endif //BARGRAPH_H
