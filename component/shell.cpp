#include "shell.h"

Shell::Shell() : m_pc(USBTX, USBRX, 9600){
	m_callback = NULL;
	m_pc.attach(callback(this, &Shell::receive));
	m_pc.printf("liason init");
}

void Shell::receive(){
	char c = m_pc.getc();
	if(c != '\n' && m_callback != NULL){
		m_message +=  c;
	}
	else if(m_callback != NULL){
		//try to analyse the msg
		//first you have to split the message by word
/*		std::string instruction;
		std::getline(m_message, instruction, ' ');
		switch(instruction){
			case "cd":
				break;
			case "ls":
				break;
			case "cat":
				break;
			default:
				pc.printf("%s : commande inconnue");
				break;
		}*/
	}
}

void Shell::set_callback(void (*funct)(void)){
	m_callback = funct;
}
