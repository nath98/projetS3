#include "random.h"

Random::Random(){

}

void Random::set_seed(int seed){
	srand(seed);
}

uint16_t Random::rand(uint16_t min, uint16_t max){
	return std::rand()%(max-min)+min;
}
