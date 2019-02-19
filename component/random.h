#ifndef RANDOM_H
#define RANDOM_H

#include "mbed.h"
#include <cstdlib>

class Random{ //:public Component{
	public:
		Random();
		uint8_t return_nb();
		void set_seed(int seed);
		uint16_t rand(uint16_t min, uint16_t max);
};

#endif //RANDOM_H
