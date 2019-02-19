#include "component.h"


Component::Component(): m_game(NULL){

}


void Component::set_game(Game* game){
	m_game = game;
}
