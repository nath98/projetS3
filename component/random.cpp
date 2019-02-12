#include "random.h"

Random::Random(){

}

void set_seed(uint16_t seed){
	srand(seed);
}

uint16_t random(uint16_t min, uint16_t max){
	return rand()%(max-min)+min;
}
