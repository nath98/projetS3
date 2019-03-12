#include "shell.h"

char printf_buffer[2000];

Shell::Shell() : RawSerial(USBTX, USBRX, 100000){
	m_callback = NULL;
	attach(callback(this, &Shell::receive));
	m_connected = true;
	m_path = "/home/falcon";
	printf_shell("liason init\n");
}

void Shell::set_connected(bool c){
	m_connected = c;
}

void Shell::receive(){
	char c = getc();
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
			printf_shell("\ncd\n");
		}
		else if(instruction == "ls"){
		
		}
		else if(instruction == "cat"){

		}
		else{
			instruction += "\n truc \n";
			//printf("%s : commande inconnue\n", instruction.c_str());
		}
		m_message = "";
	}
}

void Shell::set_callback(void (*funct)(void)){
	m_callback = funct;
}

void Shell::printf_shell(char* format, ...){
	va_list args;
	va_start(args, format);
	if(m_connected){
		printf("falcon@FX-355-pc:%s$  ", m_path.c_str());
	}
	vsprintf(printf_buffer, format, args);
	printf("%s", printf_buffer);
	va_end(args);
}
