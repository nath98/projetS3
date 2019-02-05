#include "component.h"
#include "game/game.h"

Component::Component(){
	m_game = NULL;
}

bool Component::is_free(){
	return m_game == NULL;
}


void Component::set_game(Game* game){
	if(is_free()){
		m_game = game;
	}
}

void Component::free(){
	m_game = NULL;
}

void Component::Update(){

}
