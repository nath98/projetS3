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
		string instruction;
		uint16_t i;
		for(i = 0; m_message[i]!=' '; i++){
			instruction += m_message[i];
		}
		if(instruction == "cd"){
			m_pc.printf("\ncd\n");
		}
		else if(instruction == "ls"){
		
		}
		else if(instruction == "cat"){

		}
		else{
			instruction += "\n truc \n";
			m_pc.printf("%s : commande inconnue\n", instruction.c_str());
		}
		m_message = "";
	}
}

void Shell::set_callback(void (*funct)(void)){
	m_callback = funct;
}
