#ifndef DIGITAL_H
#define DIGITAL_H

#include "mbed.h"


namespace Digital{
		uint16_t convert_tab_to_decimal(uint8_t size, uint8_t* tab, bool msb_first = true);
		uint16_t pow(uint8_t number, uint8_t power);
		char* convert_decimal_to_bin(uint16_t nb);
		void convert_int_to_char(char* text, uint16_t value, uint8_t pos);
}

#endif //DIGITAL_H
