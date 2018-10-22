#include "shell.h"

Shell::Shell() : m_pc(USBTX, USBRX, 9600){
	m_callback = NULL;
	m_pc.attach(callback(this, &Shell::receive));
	m_pc.printf("liason init");
}

void Shell::receive(){
	if(m_pc.getc() != 'o'&& m_callback != NULL){
		(*m_callback)();
	}
}

void Shell::set_callback(void (*funct)(void)){
	m_callback = funct;
}
