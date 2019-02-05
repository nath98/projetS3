#include "autentification.h"

Autentification::Autentification(/*Game_Manager* game_manager,*/ Random_Generator* random_generator, TextLCD* textLCD, Shell* shell, Keyboard* keyboard) : Game(), m_random_generator(random_generator), m_text_lcd(textLCD), m_shell(shell), m_keyboard(keyboard){

}

void Autentification::start(){
	if(m_random_generator->is_free() && m_text_lcd->is_free() && m_shell->is_free() && m_keyboard->is_free()){
		m_random_generator->set_game(this);
		m_text_lcd->set_game(this);
		m_shell->set_game(this);
		m_keyboard->set_game(this);
		for(uint8_t i = 0; i<NUMBER_OF_CARACT_IN_CODE; i++){
			m_try[i] = -1;//= 255 because of uint8_t I use 255 because if we change to use other kind of type it will still be a negative value or the biggest value
		}
		m_try_id = 0;
		m_number_of_try = 0;
		m_text_lcd->printf("code : ");	
		for(uint8_t i = 0; i < NUMBER_OF_CARACT_IN_CODE; i++){
			m_secret_number[i] = m_random_generator->rand_u16(1,9);
		}
		m_secret_number_in_dec = convert_tab_to_decimal(NUMBER_OF_CARACT_IN_CODE, m_secret_number, true);
		m_keyboard->start_scanning();
		m_shell->printf("password initialize");
	}
	else{
		m_shell->printf("ERROR !");
	}
}

void Autentification::finish(){
	m_random_generator->free();
	m_text_lcd->free();
	m_shell->free();
	m_keyboard->free();
	m_shell->printf("connexion : success !\n");
}

void Autentification::keyboard_push(uint8_t value){
	m_number_list.push(value);
}

void Autentification::Update(){
	while(!m_number_list.empty()){
		uint8_t value = m_number_list.front();
		m_number_list.pop();
		m_try[m_try_id] = value;
		m_try_id++;
		if(m_try_id >= NUMBER_OF_CARACT_IN_CODE){
			m_try_id = 0;
			if(check_code()){
				finish();
			}
			else{
				m_number_of_try++;
				if(m_number_of_try>0){
					
					m_text_lcd->printf("fail : help send on computer");
					//char text[15] = "             \n";
					//Digital::convert_int_to_char(text, m_secret_number_in_bin, 0);
					//m_shell->delay_print(text);
					m_shell->printf("bin : %x\n",(m_secret_number_in_dec));
					m_shell->printf("bin : %s\n",convert_decimal_to_bin(m_secret_number_in_dec));
				}
				for(uint8_t i = 0; i<NUMBER_OF_CARACT_IN_CODE ; i++){
					m_try[i] = -1;
				}
			}
		}
	}
}

bool Autentification::check_code(){
	bool return_value = true;
	for(uint8_t i = 0; i<NUMBER_OF_CARACT_IN_CODE; i++){
		if(m_try[i] != m_secret_number[i]){
			return_value = false;
		}
	}
	return return_value;
}
