#include "shell.h"

Shell::Shell() : RawSerial(USBTX, USBRX, 1000000){
	m_callback = NULL;
	attach(callback(this, &Shell::receive));
	printf("liason init");
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
			printf("\ncd\n");
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

//void Shell::printf(char* c){
//	printf(c);
//}
