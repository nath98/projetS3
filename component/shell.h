#ifndef SHELL_H
#define SHELL_H

#include "mbed.h"
#include <string>
#include <stdarg.h>
#include <vector>
#include <iostream>
#include <sstream>

class Shell : public RawSerial{
	public:
		Shell();
		void printf_shell(char* format, ...);
		void set_callback(void (*funct)(void));
		void set_connected(bool c);
//		void printf(char* c);

	private:
		bool m_connected;
		std::string m_message;
		std::string m_path;
		void receive();
		void (*m_callback)(void);
//		RawSerial m_pc;
};


#endif //SHELL_H
