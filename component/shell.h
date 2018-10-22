#ifndef SHELL_H
#define SHELL_H

#include "mbed.h"

class Shell{
	public:
		Shell();
//		void printf(string string);
		void set_callback(void (*funct)(void));

	private:
		void receive();
		void (*m_callback)(void);
		RawSerial m_pc;
};


#endif //SHELL_H
