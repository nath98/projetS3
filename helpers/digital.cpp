#include "digital.h"

uint16_t Digital::convert_tab_to_decimal(uint8_t size, uint8_t* tab, bool msb_first){
	uint16_t sum = 0;
	for(uint8_t i = 0; i <size; i++){
		if(msb_first){
			sum += tab[size-i-1]*pow(10,i);
		}
		else{
			sum += tab[i]*pow(10,i);
		}
	}
	return sum;
}

uint16_t Digital::pow(uint8_t number, uint8_t power){
	uint16_t prod = 1;
	for(uint8_t i =  0; i < power; i++){
		prod *= number;
	}
	return prod;
}

char* Digital::convert_decimal_to_bin(uint16_t nb){
	static char buffer[1+sizeof(uint16_t)*8] = {0};
	char *p=buffer-1+sizeof(uint16_t)*8;
	do{
		*--p = '0' + (nb&1);
		nb>>=1;
	}while(nb);
	return p;
}

void Digital::convert_int_to_char(char* text, uint16_t value, uint8_t pos){
	uint8_t taille=1;
	if(value >99){taille =3;}
	else if(value >9){taille =2;}
	for(uint8_t i = pos+taille-1; value !=0; i--){
		text[i] = value%10;
		value/10;
	}
}
