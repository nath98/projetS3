#include "shell.h"

char printf_buffer[2000];

void null_fct_shell(){

}

Shell::Shell() : RawSerial(USBTX, USBRX, 100000){
	m_callback = NULL;
	attach(callback(this, &Shell::receive));
	set_callback(&null_fct_shell);
	m_connected = true;
	m_path = "/home/falcon";
	printf_shell("liason init\n");
}

void Shell::set_connected(bool c){
	m_connected = c;
}

void Shell::receive(){
	char c = getc();
	if((c != '\n' && c!= '\r') && m_callback != NULL){
		m_message +=  c;
	}
	else if(m_callback != NULL){
		stringstream ss(m_message);
		std::vector<std::string> tableau_sous_chaine;
		std::string sous_chaine;
		int j = 0;
		while(getline(ss, sous_chaine, ' ')){
			tableau_sous_chaine.push_back(sous_chaine);
		}
		//try to analyse the msg
		//first you have to split the message by word
		string instruction = tableau_sous_chaine[0];
		uint16_t i;
		if(instruction == "cd"){
			if(tableau_sous_chaine.size()>1){
				m_path += '/' + tableau_sous_chaine[1];
				printf_shell("");
			}
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
