#include "autentification.h"

Autentification* ptr_last_initialisation_aut = NULL;

Autentification::Autentification(Game_Manager* game_manager, Board* board) : Game(), m_random_generator(&(board->random)), m_text_lcd(&(board->text_lcd)), m_shell(&(board->shell)), m_keyboard(&(board->keyboard)), m_board(board){
	ptr_last_initialisation_aut = this;
}

void Autentification::start(){
		for(uint8_t i = 0; i<NUMBER_OF_CARACT_IN_CODE; i++){
			m_try[i] = -1;//= 255 because of uint8_t I use 255 because if we change to use other kind of type it will still be a negative value or the biggest value
		}
		m_try_id = 0;
		m_number_of_try = 0;
		m_board->graphic_display.set_font((unsigned char*) Arial24x23);
		m_board->graphic_display.set_orientation(3);
		init_graphic();
		m_keyboard->set_callback_push_button(&get_keyboard_push_aut);
		for(uint8_t i = 0; i < NUMBER_OF_CARACT_IN_CODE; i++){
			m_secret_number[i] = m_random_generator->rand(1,9);
		}
		m_secret_number_in_dec = convert_tab_to_decimal(NUMBER_OF_CARACT_IN_CODE, m_secret_number, true);
		m_keyboard->start_scanning();
		m_shell->printf_shell("password initialize\n");
}

void Autentification::stop(){
	m_shell->printf("connexion : success !\n");
	m_board->graphic_display.cls();
	m_board->graphic_display.set_font((unsigned char*) Arial24x23);
	m_board->graphic_display.locate(50,100);
	m_board->graphic_display.printf("hello captain !");
}

void Autentification::keyboard_push(uint8_t value){
	m_number_list.push(value);
}

void get_keyboard_push_aut(uint8_t key){
	if(ptr_last_initialisation_aut != NULL){
		ptr_last_initialisation_aut->keyboard_push(key);
	}
	else{}
}
void Autentification::init_graphic(){
		m_board->graphic_display.cls();
		if(m_number_of_try > 0){
			m_board->graphic_display.set_font((unsigned char*) Arial12x12);
			m_board->graphic_display.locate(38, 150);
			m_board->graphic_display.printf("fail : help send on computer");
		}
		m_board->graphic_display.set_font((unsigned char*) Arial24x23);
		m_board->graphic_display.locate(50,100);
		m_board->graphic_display.printf("code : ");
}

void Autentification::toDo(){
	while(!m_number_list.empty()){
		uint8_t value = m_number_list.front();
		m_number_list.pop();
		m_try[m_try_id] = value;
		m_try_id++;
		m_board->graphic_display.printf("*");
		if(m_try_id >= NUMBER_OF_CARACT_IN_CODE){
			m_try_id = 0;
			if(check_code()){
				stop();
			}
			else{
				m_number_of_try++;
				if(m_number_of_try>0){
					
					m_shell->printf("fail : help send on computer");
					//char text[15] = "             \n";
					//Digital::convert_int_to_char(text, m_secret_number_in_bin, 0);
					//m_shell->delay_print(text);
					m_shell->printf_shell("bin : %x\n",(m_secret_number_in_dec));
					m_shell->printf_shell("bin : %s\n",convert_decimal_to_bin(m_secret_number_in_dec));
				}
				for(uint8_t i = 0; i<NUMBER_OF_CARACT_IN_CODE ; i++){
					m_try[i] = -1;
				}
				init_graphic();
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
