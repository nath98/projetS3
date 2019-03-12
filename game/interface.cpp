#include "interface.h"

Interface::Interface(Game_Manager* gm): Game(gm){
}


void Interface::start(){
	m_gm->m_board.graphic_display.printf("nouveau message !\n dans /home/mail");
}

void Interface::stop(){

}

void toDo(){

}
