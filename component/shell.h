#ifndef SHELL_H
#define SHELL_H

#include "mbed.h"
#include <string>
#include <queue>
#include "component.h"

class Component;


class Shell : public Component, public RawSerial{
	public:
		Shell();
//		void printf(string string);
		void set_callback(void (*funct)(void));
		virtual void Update();
		void delay_print(char* s);
//		void printf(char* c);

	private:
		std::string m_message;
		void receive();
		void (*m_callback)(void);
		std::queue<char*> m_list_to_print;
//		RawSerial m_pc;
};


#endif //SHELL_H
