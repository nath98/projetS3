#ifndef RANDOM_H
#define RANDOM_H

#include "mbed.h"

class Random{ //:public Component{
	public:
		Random();
		void set_seed(uint16_t seed);
		void rand(uint16_t min, uint16_t max);
};

#endif //RANDOM_H
