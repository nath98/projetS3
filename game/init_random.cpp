#include "init_random.h"

Init_Random::Init_Random(/*Game_Manager* game_manager,*/ Random_Generator* random_generator, TextLCD* text_lcd, PinName button): Game(/*game_manager*/), m_random_generator(random_generator), m_text_lcd(text_lcd), m_button(button){
	
}

void Init_Random::start(){
	m_random_generator->set_game(this);
	m_button.rise(callback(this,&Init_Random::finish));
	m_text_lcd->printf("lancez la séquence\n d’initialisation !");
}

void Init_Random::finish(){
	m_random_generator->init();
	m_random_generator->free();
	m_button.disable_irq();
	//m_text_lcd->printf("initialisation en cour");
	//wait(0.5);
	//m_text_lcd->printf(".");
	//wait(0.5);
	//m_text_lcd->printf(".");
	//wait(0.5);
	//m_text_lcd->printf(".");
	//wait(1);
	//m_text_lcd->printf("text init !");

}
/*
void Init_Random::init(){
	start_annimation();
}
*/


