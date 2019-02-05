#include "random_generator.h"

Random_Generator::Random_Generator(/*PinName interupt*/) : Component(){
	m_timer.start();
}

void Random_Generator::set_game(Game* game){
	m_game = game;
}

void Random_Generator::init(){
	srand(m_timer.read()*1000);
	m_timer.stop();
}

uint16_t Random_Generator::rand_u16(uint16_t min, uint16_t max){
	return (rand()%(max-min))+min;
}
